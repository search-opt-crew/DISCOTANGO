/**
 * Simulated Annealing for the DISCOTANGO library.
 * Copyright (c) 2015 Danny McClanahan
 *
 * DISCOTANGO is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DISCOTANGO is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with DISCOTANGO.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <math.h>
#include "../common/constants.h"
#include "../error/error.h"
#include "siman.h"

double disco_boltzmann(double E, double new_E, double T, double k) {
  double x = -(new_E - E) / (k * T);
  /* avoid underflow errors for large uphill steps */
  return (x < DISCO_LOG_DBL_MIN) ? 0.0 : exp(x);
}

/* TODO: base these defaults on something empirical */
disco_siman_options disco_siman_default_options() {
  disco_siman_options opts = {.tries_per_step = 200,
                              .iters_per_temp = 200,
                              .step_size = 1,
                              .k = 1,
                              .t_init = .008,
                              .mu_t = 1.003,
                              .t_min = 2e-6};
  return opts;
}

disco_return_t disco_siman(disco_state_const input,
                           disco_state output,
                           disco_fitness fit,
                           disco_metric metric,
                           disco_step step,
                           disco_siman_options siman_opts,
                           disco_options opts) {
  DISCO_CHECK_ARGS(input, output);
  DISCO_CHECK_OPTS(opts);
  DISCO_CHECK_FUNS(fit, metric, step);

  disco_state x, new_x, best_x;
  double E, new_E, best_E;
  double T = siman_opts.t_init, T_factor = 1.0 / siman_opts.mu_t;

  x = opts.alloc(opts.len);
  new_x = opts.alloc(opts.len);
  best_x = opts.alloc(opts.len);
  opts.copy(new_x, input, opts.len);
  opts.copy(best_x, input, opts.len);

  E = fit(input);
  best_E = E;

  while (1) {
    for (size_t i = 0; i < siman_opts.iters_per_temp; ++i) {
      opts.copy(new_x, x, opts.len);
      step(new_x, opts.rng, siman_opts.step_size);
      new_E = fit(new_x);
      /* small optimization here; record best even if it wouldn't have jumped
       * to the state */
      if (new_E < best_E) {
        opts.copy(best_x, new_x, opts.len);
        best_E = new_E;
      }
      if (new_E < E) {
        opts.copy(x, new_x, opts.len);
        E = new_E;
      } else if (opts.rng.get_double(&opts.rng.state) <
                 disco_boltzmann(E, new_E, T, siman_opts.k)) {
        opts.copy(x, new_x, opts.len);
        E = new_E;
      }
    }
    if (opts.notify) {
      opts.notify(new_x, new_E);
    }

    T *= T_factor;
    if (T < siman_opts.t_min) {
      break;
    }
  }
  opts.copy(output, best_x, opts.len);
  opts.destroy(x);
  opts.destroy(new_x);
  opts.destroy(best_x);
  return DISCO_SUCCESS;
}

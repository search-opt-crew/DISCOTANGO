/**
 * Simulated Annealing for DISCOTANGO library.
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

#include "siman.h"

/* TODO: implement these */
disco_siman_options disco_siman_default_options() {
  disco_siman_options opts = {.fit = NULL,
                              .step = NULL,
                              .tries_per_step = 1,
                              .iters_per_temp = 1,
                              .step_size = 1,
                              .k = 1,
                              .t_init = 1,
                              .mu_t = 1,
                              .t_min = 1};
  return opts;
}

disco_return_t disco_siman(disco_state_const input,
                           disco_state output,
                           disco_siman_options siman_opts
                           __attribute__((__unused__)),
                           disco_options opts) {
  DISCO_CHECK_ARGS(input, output);
  DISCO_CHECK_OPTS(opts);
  DISCO_CHECK_FUNS(siman_opts.fit, siman_opts.step);
  /* copies input to output; technically not wrong! */
  opts.copy(output, input, opts.len);
  return 0;
}

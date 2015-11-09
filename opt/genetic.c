/**
 * Genetic Programming for the DISCOTANGO library.
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

#include "genetic.h"
#include "../error/error.h"

disco_genetic_options disco_genetic_default_options() {
  disco_genetic_options opts = {.num_parents = 2,
                                .num_children    = 2,
                                .population_size = 20,
                                .mutation_chance = .1,
                                .mutation_effect = .1};
  return opts;
}

disco_return_t disco_genetic(disco_state_many_const input_set,
                             disco_state output,
                             disco_fitness fit,
                             disco_step mutate,
                             disco_genetic_crossover cross,
                             disco_genetic_options genetic_opts,
                             disco_options opts) {
  DISCO_NEED_ARGS(input_set, output);
  DISCO_CHECK_OPTS(opts);
  DISCO_NEED_FUNS(fit, mutate, cross);
  DISCO_NEED_NOTIFY(opts.notify);

  disco_state_many population =
      opts.alloc(opts.len * genetic_opts.population_size);
  disco_state best = opts.alloc(opts.len);
  double best_E = 0, E = 0;
  for (size_t i = 0; i < genetic_opts.population_size; ++i) {
    opts.copy(population[i], input_set[i], opts.len);
    E = fit(input_set[i]);
    if (E < best_E || 0 == i) {
      best_E = E;
      opts.copy(best, input_set[i], opts.len);
    }
  }

  while (1) {

  }

  opts.copy(output, best, opts.len);

  return DISCO_SUCCESS;
}

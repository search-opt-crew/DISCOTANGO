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
                             disco_mutate mutate,
                             disco_genetic_crossover cross,
                             disco_genetic_options genetic_opts,
                             disco_options opts) {
  DISCO_CHECK_ARGS(input_set, output);
  DISCO_CHECK_OPTS(opts);
  DISCO_CHECK_FUNS(fit, mutate, cross);
  DISCO_NEED_NOTIFY(opts.notify);

  disco_state_many population =
      opts.alloc(opts.len * genetic_opts.population_size);
  for (size_t i = 0; i < genetic_opts.population_size; ++i) {
    opts.copy(population[i], input_set[i], opts.len);
  }



  return DISCO_SUCCESS;
}

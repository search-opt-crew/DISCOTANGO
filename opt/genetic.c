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

#include <stdlib.h>
#include "genetic.h"
#include "../common/error.h"
#include "../common/fitness-node.h"

disco_genetic_options disco_genetic_default_options() {
  disco_genetic_options opts = {.num_parents = 2,
                                .population_size = 20,
                                .mutation_chance = .1,
                                .mutation_effect = .1};
  return opts;
}

static int disco_compare_doubles(const void * a, const void * b) {
  const double * da = (const double *) a;
  const double * db = (const double *) b;
  return (*da > *db) - (*da < *db);
}

/* discussion of selection algorithms:
   http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.11.509&rep=rep1&type=pdf */
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

  size_t state_fit_struct_size = sizeof(double) + opts.len;
  void * population =
      opts.alloc(state_fit_struct_size * genetic_opts.population_size);
  void * input_state;
  char * out_index;
  void * out_state;
  double * out_fit;
  DISCO_FITNESS_NODE_ITERATE(
      genetic_opts.population_size, state_fit_struct_size, opts.len, out_index,
      input_state, out_state, out_fit, population, input_set, {
        opts.copy(out_state, input_state, opts.len);
        *out_fit = fit(input_state);
      });

  while (1) {
    qsort(population, genetic_opts.population_size, state_fit_struct_size,
          disco_compare_doubles);

  }
  return DISCO_SUCCESS;
}

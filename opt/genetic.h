#ifndef __DISCO_GENETIC_H__
#define __DISCO_GENETIC_H__

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

#include "../common/types.h"

typedef struct {
  size_t num_parents;
  size_t population_size;
  double mutation_chance;
  double mutation_effect;
} disco_genetic_options;

typedef disco_state (*disco_genetic_crossover)(disco_state_many, size_t);

disco_genetic_options disco_genetic_default_options();

disco_return_t disco_genetic(disco_state_many_const,
                             disco_state,
                             disco_fitness,
                             disco_step,
                             disco_genetic_crossover,
                             disco_genetic_options,
                             disco_options);

#endif /* __DISCO_GENETIC_H__ */

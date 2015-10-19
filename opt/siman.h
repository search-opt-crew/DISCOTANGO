#ifndef __DISCO_SIMAN_H__
#define __DISCO_SIMAN_H__

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

#include "../common/error.h"

/* heavily drawn from the gsl_siman_solve routine in gnu gsl */

typedef struct {
  disco_fitness fit;
  disco_mutate step;
  size_t tries_per_step;
  size_t iters_per_temp;
  double step_size;
  /* boltzmann constants */
  double k, t_init, mu_t, t_min;
} disco_siman_options;

disco_return_t disco_siman(disco_state_const,
                           disco_state,
                           disco_siman_options,
                           disco_options);

#endif /* __DISCO_SIMAN_H__ */

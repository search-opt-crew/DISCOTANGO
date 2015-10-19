#ifndef __DISCO_RNG_H__
#define __DISCO_RNG_H__

/**
 * Random number generation for the DISCOTANGO library.
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

#include <stddef.h>

typedef int disco_rng_return_t;

struct disco_rng_state_struct {
  void * buf;
  size_t size;
};
typedef struct disco_rng_state_struct * disco_rng_state;
disco_rng_state disco_make_rng_state(size_t);
void disco_free_rng_state(disco_rng_state);

typedef disco_rng_return_t (*disco_get_rng)(disco_rng_state);

struct disco_rng_struct {
  disco_get_rng get;
  disco_rng_state state;
};

typedef struct disco_rng_struct * disco_rng;

disco_rng disco_make_rng();
void disco_free_rng(disco_rng);

#endif /* __DISCO_RNG_H__ */

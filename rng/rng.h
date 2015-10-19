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
#include "../libs/SFMT-src-1.4.1/SFMT.h"

typedef uint32_t disco_rng_return_t;

typedef sfmt_t disco_rng_state;

typedef disco_rng_return_t (*disco_get_random)(disco_rng_state *);

/* assumes it will be run on itself, so disco_get_random functions assume the
 * pointer passed to them is valid and DO NOT CHECK FOR NULL. */
typedef struct {
  disco_get_random get;
  disco_rng_state state;
} disco_rng;

disco_rng disco_default_rng();

#endif /* __DISCO_RNG_H__ */

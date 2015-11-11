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

typedef sfmt_t disco_rng_state;

typedef uint32_t (*disco_rng_get_uint32)(disco_rng_state *);
typedef uint64_t (*disco_rng_get_uint64)(disco_rng_state *);
typedef double (*disco_rng_get_double)(disco_rng_state *);

/* assumes it will be run on itself, so disco_get_random functions assume the
 * pointer passed to them is valid and DO NOT CHECK FOR NULL. */
typedef struct disco_rng_struct {
  disco_rng_get_uint32 get_32;
  disco_rng_get_uint64 get_64;
  disco_rng_get_double get_double;
  disco_rng_state state;
} disco_rng;

disco_rng disco_default_rng();
disco_rng disco_default_rng_with_seed();

#define DISCO_CHECK_RNG(rng)                             \
  do {                                                   \
    if (!rng.get_32) { return DISCO_NO_RNG_32; }         \
    if (!rng.get_64) { return DISCO_NO_RNG_64; }         \
    if (!rng.get_double) { return DISCO_NO_RNG_DOUBLE; } \
  } while (0)

#endif /* __DISCO_RNG_H__ */

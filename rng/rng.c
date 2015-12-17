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

#include <time.h>
#include <stdlib.h>
#include "rng.h"
#include "../libs/SFMT-src-1.4.1/SFMT.h"

disco_rng * disco_default_rng() {
  return disco_default_rng_with_seed(time(NULL));
}

static inline uint32_t disco_get_32_sfmt(disco_rng_state state) {
  return sfmt_genrand_uint32((sfmt_t *) state);
}

static inline uint64_t disco_get_64_sfmt(disco_rng_state state) {
  return sfmt_genrand_uint64((sfmt_t *) state);
}

static inline double disco_get_double_sfmt(disco_rng_state state) {
  return sfmt_genrand_real1((sfmt_t *) state);
}

disco_rng * disco_default_rng_with_seed(uint32_t seed) {
  disco_rng * rng = malloc(sizeof(disco_rng));
  rng->get_32     = disco_get_32_sfmt;
  rng->get_64     = disco_get_64_sfmt;
  rng->get_double = disco_get_double_sfmt;
  rng->state = malloc(sizeof(sfmt_t));
  sfmt_init_gen_rand((sfmt_t *) rng->state, seed);
  return rng;
}

void disco_free_rng(disco_rng * rng) {
  free(rng);
}

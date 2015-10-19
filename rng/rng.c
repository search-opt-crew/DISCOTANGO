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

#include "rng.h"

/* TODO: add real random function */
disco_rng_return_t disco_default_get_rng(disco_rng_state * st) {
  if (*st > 0) {
    *st = 0;
  } else {
    *st = 1;
  }
  return *st;
}

disco_rng disco_default_rng() {
  disco_rng rng = {.get = disco_default_get_rng, .state = 0};
  return rng;
}

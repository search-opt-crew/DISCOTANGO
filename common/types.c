/**
 * Type definitions for the DISCOTANGO library.
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

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "types.h"

static disco_options disco_get_default_options(size_t len) {
  disco_options opts = {.notify = NULL,
                        .alloc   = malloc,
                        .copy    = memcpy,
                        .destroy = free,
                        .len     = len};
  return opts;
}

disco_options disco_default_options(size_t len) {
  disco_options opts = disco_get_default_options(len);
  opts.rng           = disco_default_rng();
  return opts;
}

disco_options disco_default_options_with_seed(size_t len, uint32_t seed) {
  disco_options opts = disco_get_default_options(len);
  opts.rng           = disco_default_rng_with_seed(seed);
  return opts;
}

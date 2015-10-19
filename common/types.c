/**
 * Type definitions for DISCOTANGO library.
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
#include "types.h"

disco_options disco_make_opts() {
  disco_options opts = malloc(sizeof(struct disco_options_struct));
  opts->printf = NULL;
  opts->copy = memcpy;
  opts->destroy = free;
  opts->rng = disco_make_rng();
  return opts;
}

void disco_free_opts(disco_options opts) {
  if (opts) {
    disco_free_rng(opts->rng);
    free(opts);
  }
}

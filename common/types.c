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

#include "types.h"

const disco_opts_t DISCO_DEFAULT_OPTS = {
    .printf = NULL, .copy = NULL, .destroy = NULL};

disco_opts_t disco_default_opts() {
  disco_opts_t opts = {.printf = DISCO_DEFAULT_OPTS.printf,
                       .copy = DISCO_DEFAULT_OPTS.copy,
                       .destroy = DISCO_DEFAULT_OPTS.destroy};
  return opts;
}

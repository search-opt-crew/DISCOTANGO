/**
 * Error codes and handling functions for the DISCOTANGO library.
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

#include <stdarg.h>
#include "error.h"

#define DISCO_ERRSTR(codename, errstr) ("DISCOTANGO: " #codename ": " errstr)

const disco_return_t DISCO_SUCCESS = 0;
const disco_return_t DISCO_NULL_ARG = -1;
const disco_return_t DISCO_NO_ALLOC = -2;
const disco_return_t DISCO_NO_COPY = -3;
const disco_return_t DISCO_NO_DESTROY = -4;
const disco_return_t DISCO_NO_FUN = -5;

/* wish there was a more reliable way to report error values that didn't require
 * giving the same error code twice, but C macros don't really give us much
 * leeway. */
static const char * disco_unrecognized_error =
    "DISCOTANGO: unrecognized error code";
const char * disco_errstr(disco_return_t err) {
  switch (err) {
  case 0:
    return DISCO_ERRSTR(DISCO_SUCCESS, "success");
  case -1:
    return DISCO_ERRSTR(DISCO_NULL_ARG, "null argument");
  case -2:
    return DISCO_ERRSTR(DISCO_NO_ALLOC, "alloc operation is null");
  case -3:
    return DISCO_ERRSTR(DISCO_NO_COPY, "copy operation is null");
  case -4:
    return DISCO_ERRSTR(DISCO_NO_DESTROY, "destroy operation is null");
  case -5:
    return DISCO_ERRSTR(DISCO_NO_FUN, "required function was not provided");
  default:
    return disco_unrecognized_error;
  }
}

bool disco_check_args(int num, ...) {
  va_list ptrs;
  va_start(ptrs, num);
  for (int i = 0; i < num; ++i) {
    if (!va_arg(ptrs, void *) ) {
      return true;
    }
  }
  va_end(ptrs);
  return false;
}

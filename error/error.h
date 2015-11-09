#ifndef __DISCO_ERROR_H__
#define __DISCO_ERROR_H__

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

#include "../common/types.h"

const disco_return_t DISCO_SUCCESS;
const disco_return_t DISCO_NULL_ARG;
const disco_return_t DISCO_NO_ALLOC;
const disco_return_t DISCO_NO_COPY;
const disco_return_t DISCO_NO_DESTROY;
const disco_return_t DISCO_NO_FUN;
const disco_return_t DISCO_NO_NOTIFY;
const disco_return_t DISCO_NO_RNG_32;
const disco_return_t DISCO_NO_RNG_64;
const disco_return_t DISCO_NO_RNG_DOUBLE;

const char * disco_errstr(disco_return_t);

bool disco_check_args(int, ...);

/* Fails if no arguments are given. */
#define DISCO_CHECK_MACRO(err, ...)                                  \
  do {                                                               \
    if (disco_check_args(DISCO_PP_NARG(__VA_ARGS__), __VA_ARGS__)) { \
      return err;                                                    \
    }                                                                \
  } while (0)
#define DISCO_NEED_ARGS(...) DISCO_CHECK_MACRO(DISCO_NULL_ARG, __VA_ARGS__)
#define DISCO_NEED_FUNS(...) DISCO_CHECK_MACRO(DISCO_NO_FUN, __VA_ARGS__)

#define DISCO_CHECK_OPTS(opts)                      \
  do {                                              \
    if (!opts.alloc) { return DISCO_NO_ALLOC; }     \
    if (!opts.copy) { return DISCO_NO_COPY; }       \
    if (!opts.destroy) { return DISCO_NO_DESTROY; } \
    DISCO_CHECK_RNG(opts.rng);                      \
  } while (0)

#define DISCO_NEED_NOTIFY(notify)            \
  do {                                       \
    if (!notify) { return DISCO_NO_NOTIFY; } \
  } while (0)

#endif /* __DISCO_ERROR_H__ */

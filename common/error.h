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

#include "types.h"

const disco_return_t DISCO_NULL_ARG;
const disco_return_t DISCO_NO_OPTS;
const disco_return_t DISCO_NO_COPY;
const disco_return_t DISCO_NO_DESTROY;
const disco_return_t DISCO_NO_RNG;

const char * disco_errstr(disco_return_t);

bool disco_check_args(int, ...);

/* Fails if no arguments are given. */
#define DISCO_CHECK_ARGS(...)                                        \
  do {                                                               \
    if (disco_check_args(DISCO_PP_NARG(__VA_ARGS__), __VA_ARGS__)) { \
      return DISCO_NULL_ARG;                                      \
    }                                                                \
  } while (0)

#define DISCO_CHECK_OPTS(opts)   \
  do {                           \
    if (!opts) {                 \
      return DISCO_NO_OPTS;      \
    } else {                     \
      if (!opts->copy) {          \
        return DISCO_NO_COPY;    \
      }                          \
      if (!opts->destroy) {       \
        return DISCO_NO_DESTROY; \
      }                          \
      if (!opts->rng) {           \
        return DISCO_NO_RNG;     \
      }                          \
    }                            \
  } while (0)

#endif /* __DISCO_ERROR_H__ */

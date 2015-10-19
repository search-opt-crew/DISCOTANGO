#ifndef __DISCO_TYPEDEFS_H__
#define __DISCO_TYPEDEFS_H__

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

#include <stdbool.h>
#include <stddef.h>
#include "macros.h"
#include "../rng/rng.h"

/* arguments which can be used by all functions in the library. if you must
 * make a new type of argument, add it here, then add it to your function. */
typedef int disco_return_t;
typedef double (*disco_fitness)(void *);
typedef int (*disco_fitness_discrete)(void *);
typedef size_t (*disco_fitness_nonnegative)(void *);
typedef void * disco_state;
typedef void * (*disco_mutate)(void *);

/* common options for all functions. all of these have sane defaults, specified
 * at bottom. */
typedef void (*disco_print)(void *);
/* copy from argument 2 to argument 1 (which /does/ point to already allocated
 * memory). return the newly constructed value. */
typedef void * (*disco_copy)(void *, const void *, size_t);
typedef void (*disco_destroy)(void *);

typedef struct {
  disco_print printf;
  disco_copy copy;
  disco_destroy destroy;
  disco_rng rng;
} disco_options;

disco_options disco_default_options();

#endif /* __DISCO_TYPEDEFS_H__ */

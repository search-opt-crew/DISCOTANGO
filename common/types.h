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

#include <stddef.h>

/* arguments which can be used by all functions in the library. if you must
 * make a new type of argument, add it here, then add it to your function. */
typedef int disco_return_t;
typedef double (*disco_fitness_fun)(void *);
typedef int (*disco_fitness_fun_discrete)(void *);
typedef size_t (*disco_fitness_fun_nonnegative)(void *);
typedef void * disco_input_t;
typedef void * disco_output_t;

/* common options for all functions. all of these have sane defaults, specified
 * at bottom. */
typedef void (*disco_print_fun)(void *);
/* copy from argument 1 to argument 2 (which does not point to already allocated
 * memory). return the newly constructed value. */
typedef void * (*disco_copy_fun)(void *, void *);
typedef void (*disco_destroy_fun)(void *);
/* TODO: make rng type (steal from somewhere) */

struct disco_options {
  disco_print_fun printf;
  disco_copy_fun copy;
  disco_destroy_fun destroy;
};
typedef struct disco_options * disco_opts_t;

/* defaults for options */
const struct disco_options DEFAULT_DISCO_OPTS_STRUCT = {NULL, NULL, NULL};
const struct disco_options * const DEFAULT_DISCO_OPTS =
    &DEFAULT_DISCO_OPTS_STRUCT;

#endif /* __DISCO_TYPEDEFS_H__ */

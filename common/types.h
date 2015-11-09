#ifndef __DISCO_TYPEDEFS_H__
#define __DISCO_TYPEDEFS_H__

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

#include <stdbool.h>
#include <stddef.h>
#include "macros.h"
#include "../rng/rng.h"

/* arguments which can be used by all functions in the library. if you must
 * make a new type of argument, add it here, then add it to your function. */
typedef int disco_return_t;
typedef void * disco_state;
typedef disco_state * disco_state_many;
typedef const void * disco_state_const;
typedef const disco_state_const * disco_state_many_const;
typedef double (*disco_fitness)(disco_state_const);
typedef disco_state (*disco_step)(disco_state, disco_rng, double);
typedef disco_state (*disco_mutate)(disco_state, disco_rng);
typedef double (*disco_metric)(disco_state_const, disco_state_const);

/* common options for all functions. all of these have sane defaults, specified
 * at bottom. */
/* returns true if function should cease execution */
typedef bool (*disco_notify)(disco_state_const, double);
typedef disco_state (*disco_alloc)(size_t);
/* copy from argument 2 to argument 1 (which /does/ point to already allocated
 * memory). return the newly constructed value. */
typedef disco_state (*disco_copy)(disco_state, disco_state_const, size_t);
typedef void (*disco_destroy)(disco_state);

typedef struct disco_options_struct {
  disco_notify notify;
  disco_alloc alloc;
  disco_copy copy;
  disco_destroy destroy;
  disco_rng rng;
  size_t len; /* size of disco_state used in problem */
} disco_options;

disco_options disco_default_options(size_t);

#endif /* __DISCO_TYPEDEFS_H__ */

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

#include <stdlib.h>
#include <stdbool.h>
#include "rng.h"

disco_rng_state disco_make_rng_state(size_t len) {
  disco_rng_state st = malloc(sizeof(struct disco_rng_state_struct));
  st->buf = malloc(len);
  st->size = len;
  return st;
}
void disco_free_rng_state(disco_rng_state st) {
  if (st) {
    free(st->buf);
    free(st);
  }
}

/* TODO: add real random function */
bool disco_rng_state_is_valid(disco_rng_state st) {
  return st && st->buf;
}
disco_rng_return_t disco_default_get_rng(disco_rng_state st) {
  if (!disco_rng_state_is_valid(st)) {
    return -1;
  }
  if (*((bool *) st->buf)) {
    *((bool *) st->buf) = false;
    return 1;
  } else {
    *((bool *) st->buf) = true;
    return 0;
  }
}

disco_rng disco_make_rng() {
  disco_rng rng = malloc(sizeof(struct disco_rng_struct));
  rng->get = disco_default_get_rng;
  rng->state = disco_make_rng_state(sizeof(bool));
  *((bool *) rng->state->buf) = false;
  return rng;
}

void disco_free_rng(disco_rng rng) {
  if (rng) {
    disco_free_rng_state(rng->state);
    free(rng);
  }
}

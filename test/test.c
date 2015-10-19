/**
 * Testing for the DISCOTANGO library.
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
#include <stdio.h>
#include "../opt/siman.h"

int main() {
  disco_siman_options sopts = disco_siman_default_options();
  disco_state test_in = malloc(1), test_out = malloc(1);
  disco_options opts = disco_default_options();
  disco_return_t ret = disco_siman(test_in, test_out, sopts, opts);
  printf("%zu\n", opts.rng.get(&opts.rng.state));
  free(test_in);
  free(test_out);
  if (ret) {
    printf("%s\n", disco_errstr(ret));
  } else {
    printf("%s\n", "no errors!");
  }
}

/**
 * Testing of Simulated Annealing for the DISCOTANGO library.
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

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../opt/siman.h"
#include "../libs/Unity-master/src/unity.h"
#include "../libs/Unity-master/extras/fixture/src/unity_fixture.h"

/* drawn from
 * https://www.gnu.org/software/gsl/manual/html_node/Trivial-example.html */

double E1(disco_state_const xp) {
  double x = *((double *) xp);
  return exp(-pow((x - 1), 2)) * sin(8 * x);
}

disco_state S1(disco_state xp, disco_rng r, double step_size) {
  double * x = (double *) xp;
  *x = r.get_double(&r.state) * 2 * step_size - step_size + *x;
  return (disco_state) x;
}

void P1(disco_state xp) {
  printf("%12g", *((double *) xp));
}

double M1(disco_state xp, disco_state yp) {
  return fabs(*((double *) xp) - *((double *) yp));
}

const double TEST_FLOAT_TOLERANCE = .05;

TEST_GROUP(siman);

TEST_SETUP(siman) {
}

TEST_TEAR_DOWN(siman) {
}

TEST(siman, EqualsGSL) {
  disco_siman_options sopts = disco_siman_default_options();
  disco_state test_in = malloc(sizeof(double)),
              test_out = malloc(sizeof(double));
  *((double *) test_in) = 0;
  disco_options opts = disco_default_options(sizeof(double));
  disco_return_t ret = disco_siman(test_in, test_out, E1, M1, S1, sopts, opts);
  TEST_ASSERT_EQUAL_MESSAGE(0, ret, disco_errstr(ret));
  TEST_ASSERT_FLOAT_WITHIN_MESSAGE(TEST_FLOAT_TOLERANCE, 1.363131,
                                   *((double *) test_out),
                                   "should be 1.363131");
  free(test_in);
  free(test_out);
}

TEST_GROUP_RUNNER(siman) {
  RUN_TEST_CASE(siman, EqualsGSL);
}

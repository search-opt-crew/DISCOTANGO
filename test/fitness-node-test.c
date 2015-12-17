#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../common/fitness-node.h"
#include "../libs/Unity/src/unity.h"
#include "../libs/Unity/extras/fixture/src/unity_fixture.h"

/* TODO: fix this into complete sorting test */

static int disco_compare_doubles(const void * a, const void * b) {
  const double * da = (const double *) a;
  const double * db = (const double *) b;
  return (*da > *db) - (*da < *db);
}

double fit(void * inp) {
  return (double) *((int *) inp);
}

TEST_GROUP(fitnessnode);

TEST_SETUP(fitnessnode) {}

TEST_TEAR_DOWN(fitnessnode) {}

TEST(fitnessnode, loopworks) {
  srand(time(NULL));
  const size_t num = 15;
  int arr[num];
  for (size_t i = 0; i < num; ++i) { arr[i] = rand(); }
  size_t state_fit_struct_size = sizeof(double) + sizeof(int);
  void * population            = malloc(state_fit_struct_size * num);
  void * input_state;
  char * cur_index;
  void * cur_state;
  double * cur_fit;
  DISCO_FITNESS_NODE_ITERATE(num, state_fit_struct_size, sizeof(int), cur_index,
                             input_state, cur_state, cur_fit, population, arr, {
                               memcpy(cur_state, input_state, sizeof(int));
                               *cur_fit = fit(input_state);
                             });
  qsort(population, num, state_fit_struct_size, disco_compare_doubles);
  bool first_el = true;
  int prev_el;
  DISCO_FITNESS_NODE_ITERATE(num, state_fit_struct_size, sizeof(int), cur_index,
                             input_state, cur_state, cur_fit, population, arr, {
                               if (!first_el) {
                                 TEST_ASSERT_TRUE(*((int *) cur_state) >=
                                                  prev_el);
                               }
                               first_el = false;
                               prev_el = *((int *) cur_state);
                             });
  free(population);
}

TEST_GROUP_RUNNER(fitnessnode) {
  RUN_TEST_CASE(fitnessnode, loopworks);
}

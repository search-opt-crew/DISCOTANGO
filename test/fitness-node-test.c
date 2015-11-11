#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "../common/fitness-node.h"

/* TODO: fix this into complete sorting test */

static int disco_compare_doubles(const void * a, const void * b) {
  const double * da = (const double *) a;
  const double * db = (const double *) b;
  return (*da > *db) - (*da < *db);
}

double fit(void * inp) {
  return (double) *((int *) inp);
}

int main() {
  srand(time(NULL));
  const size_t num = 15;
  int arr[num];
  for (size_t i = 0; i < num; ++i) {
    arr[i] = rand();
  }
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
  DISCO_FITNESS_NODE_ITERATE(num, state_fit_struct_size, sizeof(int), cur_index,
                             input_state, cur_state, cur_fit, population, arr,
                             { printf("%d\n", *((int *) cur_state)); });
  free(population);
}

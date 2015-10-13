#include "../common/error.h"
#include "siman.h"

int disco_siman(disco_fitness_fun fit,
             disco_input_data input,
             disco_output_data output) {
  DISCO_CHECK_ARGS(fit, input, output);
  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include "../opt/siman.h"

int main() {
  disco_siman_options sopts;
  disco_state test_inp = malloc(1);
  disco_options opts = disco_make_opts();
  disco_return_t ret = disco_siman(test_inp, sopts, opts);
  free(test_inp);
  disco_free_opts(opts);
  if (ret) {
    printf("%s\n", disco_errstr(ret));
  } else {
    printf("%s\n", "no errors!");
  }
}

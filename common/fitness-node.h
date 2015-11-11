#ifndef __DISCO_FITNESS_NODE_H__
#define __DISCO_FITNESS_NODE_H__

/* compile-time error if char is not a single byte */
static int disco_check_byte __attribute__((unused)) = 1 / (sizeof(char) == 1);

#define DISCO_FITNESS_NODE_ITERATE(arr_len, struct_size, data_size, out_ind, \
                                   in_state, out_state, out_fit, out_arr,    \
                                   in_arr, stmts)                            \
  do {                                                                       \
    for (size_t _____ind = 0; _____ind < (arr_len); ++_____ind) {            \
      (out_ind) = ((char *) (out_arr)) + (_____ind * (struct_size));         \
      (in_state) = (void *) ((char *) (in_arr)) + (_____ind * (data_size));  \
      (out_state) = (out_ind) + sizeof(double);                              \
      (out_fit) = (double *) (out_ind);                                      \
      do { stmts } while (0);                                                \
    }                                                                        \
  } while (0)

#endif /* __DISCO_FITNESS_NODE_H__ */

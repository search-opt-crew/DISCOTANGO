#ifndef __DISCO_ERROR_H__
#define __DISCO_ERROR_H__

#include <stdarg.h>

const int DISCO_INVALID_ARG = -1;
const int DISCO_DIV_0 = -2;

/* TODO: write this, figure out how to return specified error correctly */
int disco_check_args(int err, ...) { return err; }

#define DISCO_CHECK_ARGS(...)                                                  \
  do {                                                                         \
    if (disco_check_args(DISCO_INVALID_ARG, __VA_ARGS__)) {                    \
      return DISCO_INVALID_ARG;                                                \
    }                                                                          \
  } while (0)

#endif /* __DISCO_ERROR_H__ */

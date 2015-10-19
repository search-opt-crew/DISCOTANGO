#ifndef __DISCO_RNG_H__
#define __DISCO_RNG_H__

#include <stddef.h>

typedef int disco_rng_return_t;

struct disco_rng_state_struct {
  void * buf;
  size_t size;
};
typedef struct disco_rng_state_struct * disco_rng_state;
disco_rng_state disco_make_rng_state(size_t);
void disco_free_rng_state(disco_rng_state);

typedef disco_rng_return_t (*disco_get_rng)(disco_rng_state);

struct disco_rng_struct {
  disco_get_rng get;
  disco_rng_state state;
};

typedef struct disco_rng_struct * disco_rng;

disco_rng disco_make_rng();
void disco_free_rng(disco_rng);

#endif /* __DISCO_RNG_H__ */

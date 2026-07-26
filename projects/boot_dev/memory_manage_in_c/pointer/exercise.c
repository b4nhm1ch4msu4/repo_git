#include "exercise.h"
#include <stdlib.h>

token_t **create_token_pointer_array(token_t *tokens, size_t count) {
  token_t **token_pointers = malloc(count * sizeof(token_t *));
  if (token_pointers == NULL) {
    exit(1);
  }
  for (size_t i = 0; i < count; ++i) {
    token_pointers[i] = &tokens[i];
  }
  return token_pointers;
}

void snek_zero_out(void *ptr, snek_object_kind_t kind) {
  switch (kind) {
  case INTEGER:
    ((snek_int_t *)ptr)->value = 0;
    break;
  case FLOAT:
    ((snek_float_t *)ptr)->value = 0.0f;
    break;
  case BOOL:
    ((snek_bool_t *)ptr)->value = 0u;
    break;
  }
}

#include "snekobject.h"
#include <stdlib.h>

snek_object_t *new_snek_integer(int value) {
  snek_object_t *new_obj = malloc(sizeof(snek_object_t));
  if (new_obj == NULL) {
    return NULL;
  }
  new_obj->kind = INTERGER;
  new_obj->data.v_int = value;
  return new_obj;
}

snek_object_t *new_snek_float(float value) {
  snek_object_t *new_obj = malloc(sizeof(snek_object_t));
  if (new_obj == NULL) {
    return NULL;
  }
  new_obj->kind = FLOAT;
  new_obj->data.v_float = value;
  return new_obj;
}

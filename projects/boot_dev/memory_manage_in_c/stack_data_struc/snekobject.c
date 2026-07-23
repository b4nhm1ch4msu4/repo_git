#include "snekobject.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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
snek_object_t *new_snek_string(char *value) {
  snek_object_t *new_obj = malloc(sizeof(snek_object_t));
  if (new_obj == NULL) {
    return NULL;
  }
  size_t len = strlen(value);
  char *new_data = malloc(len + 1);
  if (new_data == NULL) {
    free(new_obj);
    return NULL;
  }
  strcpy(new_data, value);
  new_obj->kind = STRING;
  new_obj->data.v_string = new_data;
  return new_obj;
}

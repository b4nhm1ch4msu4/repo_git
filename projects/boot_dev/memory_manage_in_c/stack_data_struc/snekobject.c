#include "snekobject.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

snek_object_t *snek_array_get(snek_object_t *snek_obj, size_t index) {
  if (snek_obj == NULL) {
    return NULL;
  }
  if (snek_obj->kind != ARRAY) {
    return NULL;
  }
  if (index >= snek_obj->data.v_array.size) {
    return NULL;
  }
  return snek_obj->data.v_array.elements[index];
}
bool snek_array_set(snek_object_t *snek_obj, size_t index,
                    snek_object_t *value) {
  if (snek_obj == NULL || value == NULL) {
    return false;
  }
  if (snek_obj->kind != ARRAY) {
    return false;
  }
  if (index >= snek_obj->data.v_array.size) {
    return false;
  }
  snek_obj->data.v_array.elements[index] = value;
  return true;
}
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

snek_object_t *new_snek_vector3(snek_object_t *x, snek_object_t *y,
                                snek_object_t *z) {
  if (x == NULL || y == NULL || z == NULL) {
    return NULL;
  }
  snek_object_t *new_obj = malloc(sizeof(snek_object_t));
  if (new_obj == NULL) {
    return NULL;
  }
  new_obj->kind = VECTOR3;
  snek_vector_t v = {x, y, z};
  new_obj->data.v_vector3 = v;
  return new_obj;
}

snek_object_t *new_snek_array(size_t size) {
  snek_object_t *new_obj = malloc(sizeof(snek_object_t));
  if (new_obj == NULL) {
    return NULL;
  }
  snek_object_t **arr = calloc(size, sizeof(snek_object_t *));
  if (new_obj == NULL) {
    free(new_obj);
    return NULL;
  }
  new_obj->kind = ARRAY;
  snek_array_t a = {size, arr};
  new_obj->data.v_array = a;
  return new_obj;
}

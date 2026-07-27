#include "snekobject.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

snek_object_t *snek_add(snek_object_t *a, snek_object_t *b) {
  if (a == NULL || b == NULL) {
    return NULL;
  }
  if (a->kind == INTERGER) {
    if (b->kind == INTERGER) {
      snek_object_t *c = new_snek_integer(a->data.v_int + b->data.v_int);
      return c;
    } else if (b->kind == FLOAT) {
      snek_object_t *c = new_snek_float(a->data.v_int + b->data.v_float);
      return c;
    } else {
      return NULL;
    }
  } else if (a->kind == FLOAT) {
    if (b->kind == FLOAT || b->kind == INTERGER) {
      snek_object_t *c = new_snek_float(a->data.v_float + b->data.v_float);
      return c;
    } else {
      return NULL;
    }

  } else if (a->kind == STRING) {
    if (b->kind != STRING) {
      return NULL;
    } else {
      size_t c_size = strlen(a->data.v_string) + strlen(b->data.v_string);
      char *c_str = calloc(c_size, 1);
      strcat(c_str, a->data.v_string);
      strcat(c_str, b->data.v_string);
      snek_object_t *c = new_snek_string(c_str);
      free(c_str);
      return c;
    }
  } else if (a->kind == VECTOR3) {
    if (b->kind != VECTOR3) {
      return NULL;
    }
    snek_object_t *c_x = snek_add(a->data.v_vector3.x, b->data.v_vector3.x);
    // printf("vector c_x : %f", c_x->data.v_float);
    snek_object_t *c_y = snek_add(a->data.v_vector3.y, b->data.v_vector3.y);
    // printf("vector c_y : %f", c_y->data.v_float);
    snek_object_t *c_z = snek_add(a->data.v_vector3.z, b->data.v_vector3.z);
    // printf("vector c_z : %f", c_z->data.v_float);
    snek_object_t *c = new_snek_vector3(c_x, c_y, c_z);
    return c;
  } else if (a->kind == ARRAY) {
    if (b->kind != ARRAY) {
      return NULL;
    } else {
      size_t a_size = a->data.v_array.size;
      size_t b_size = b->data.v_array.size;
      size_t c_size = a_size + b_size;
      snek_object_t *c = new_snek_array(c_size);
      for (size_t i = 0; i < a_size; i++) {
        snek_array_set(c, i, snek_array_get(a, i));
      }
      for (size_t i = a_size; i < c->data.v_array.size; i++) {
        snek_array_set(c, i, snek_array_get(b, i - a_size));
      }
      return c;
    }
  } else {
    return NULL;
  }
}
int snek_length(snek_object_t *obj) {
  if (obj == NULL) {
    return -1;
  }
  if (obj->kind == INTERGER) {
    return 1;
  }
  if (obj->kind == FLOAT) {
    return 1;
  }
  if (obj->kind == STRING) {
    return strlen(obj->data.v_string);
  }
  if (obj->kind == VECTOR3) {
    return 3;
  }
  if (obj->kind == ARRAY) {
    return obj->data.v_array.size;
  }
  return -1;
}
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

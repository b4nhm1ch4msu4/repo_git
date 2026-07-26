#include <stddef.h>

typedef struct Token {
  char *literal;
  int line;
  int column;
} token_t;

token_t **create_token_pointer_array(token_t *tokens, size_t count);

// ----------------------------------------------------------------------

typedef enum SnekObjectKind {
  INTEGER,
  FLOAT,
  BOOL,
} snek_object_kind_t;

typedef struct SnekInt {
  char *name;
  int value;
} snek_int_t;

typedef struct SnekFloat {
  char *name;
  long _pad;
  float value;
} snek_float_t;

typedef struct SnekBool {
  char *name;
  long _pad;
  unsigned int value;
} snek_bool_t;

void snek_zero_out(void *ptr, snek_object_kind_t kind);

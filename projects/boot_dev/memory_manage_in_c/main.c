#include <stdio.h>
typedef union name_or_age {
  int age;
  char *name;
} age_or_name_t;

int main (int argc, char *argv[]) {
  age_or_name_t name = {.name = "tienp"};
  printf("%s", name.name);
  return 0;
}

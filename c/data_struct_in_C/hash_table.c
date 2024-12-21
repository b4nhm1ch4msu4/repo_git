#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAP 100
#define VALUE_CAP 20

typedef struct Pair {
  int key;
  char value[VALUE_CAP];
} Pair;

Pair *ht_init();
int hash_func(int key);
char *get(Pair *ht, int key);
void put(Pair *ht, int key, char *value);

Pair *ht_init() {
  Pair *ht = calloc(INIT_CAP, sizeof(Pair));
  return (ht == NULL) ? NULL : ht;
}

int hash_func(int key) { return key % INIT_CAP; }

char *get(Pair *ht, int key){
  int index = hash_func(key);
  return ht[index].value;
}

void put(Pair *ht, int key, char *value){
  int index = hash_func(key);
  ht[index].key = key;
  strcpy(ht[index].value, value);
}

int main(int argc, char *argv[])
{
  Pair *my_ht = ht_init();
  put(my_ht, 1, "tien");
  put(my_ht, 2, "pham");

  printf("Key: %d\nValue: %s",2,get(my_ht, 2));


  free(my_ht);
  return EXIT_SUCCESS;
}

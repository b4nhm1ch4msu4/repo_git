#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_CAP 10
#define VALUE_SIZE 20

typedef struct Pair {
  int key;
  char value[VALUE_SIZE];
  struct Pair *next;
} Pair;

Pair *ht_init();
int hash_func(int key);
char *get(Pair *ht, int key);
void put(Pair *ht, int key, char *value);

Pair *ht_init() {
  Pair *bucket = calloc(INIT_CAP, sizeof(Pair));
  if (bucket != NULL)
    for (int i = 0; i < INIT_CAP; i++) {
      bucket[i].next = NULL;
    }
  return bucket;
}

int hash_func(int key) { return key % INIT_CAP; }

char *get(Pair *bucket, int key) {
  int index = hash_func(key);
  Pair *cur = &bucket[index];
  do {
    if (cur->key == key)
      return cur->value;
    else
      cur = cur->next;
  } while (cur != NULL);
  return NULL;
}

void put(Pair *bucket, int key, char *value) {
  int index = hash_func(key);
  Pair *cur = &bucket[index];
  while (cur != NULL) {
    if (cur->key == key) {
      strcpy(cur->value, value);
      return;
    }
    if (cur->next == NULL) {
      Pair *new_pair = calloc(1, sizeof(Pair));
      new_pair->key = key;
      strcpy(new_pair->value, value);
      cur->next = new_pair;
      return;
    }
    cur = cur->next;
  }
}

int main(int argc, char *argv[]) {
  Pair *bucket = ht_init();
  if (bucket == NULL) {
    printf("init bucket fail !!!");
    return EXIT_FAILURE;
  }
  put(bucket, 1, "tien");
  put(bucket, 11, "van");
  put(bucket, 21, "vanvan");
  put(bucket, 2, "pham");

  printf("Key: %d\nValue: %s\n", 1, get(bucket, 1));
  put(bucket, 1, "tiennew");
  printf("Key: %d\nValue: %s\n", 1, get(bucket, 1));

  free(bucket);
  return EXIT_SUCCESS;
}

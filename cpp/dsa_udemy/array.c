#include <stdio.h>
#include <stdlib.h>
struct Array {
  int *arr;
  int length;
  int size;
};

void Display(struct Array *a) {
  for (int i = 0; i < a->length; i++) {
    printf("%d ", a->arr[i]);
  }
  printf("\n");
}

void Append(struct Array *a, int value) {
  a->arr[a->length] = value;
  a->length++;
}

void Insert(struct Array *a, int index, int value) {
  for (int i = a->length; i > index; i--) {
    a->arr[i] = a->arr[i - 1];
  }
  a->arr[index] = value;
    a->length++;
}

int main(int argc, char *argv[]) {
  struct Array a;
  printf("Enter the size of array: ");
  scanf("%d", &a.size);
  a.arr = (int *)malloc(sizeof(int) * a.size);

  printf("Enter number of numbers : ");
  scanf("%d", &a.length);
  for (int i = 0; i < a.length; i++) {
    scanf("%d", &a.arr[i]);
  }

  Display(&a);
  printf("Append value 20 to array!!!\n");
  Append(&a, 20);
  printf("New array:");
  Display(&a);
  printf("Insert value 30 at index 5 to array!!!\n");
  Insert(&a, 5, 30);
  printf("New array:\n");
  Display(&a);
  return 0;
}

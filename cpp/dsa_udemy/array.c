#include <stdio.h>
#include <stdlib.h>
struct Array {
  int *arr;
  int length;
  int size;
};

void Display(struct Array *a) {
  printf("Array: ");
  for (int i = 0; i < a->length; i++) {
    printf("%d ", a->arr[i]);
  }
  printf("\n");
}

void Append(struct Array *a, int value) {
  printf("Append value %d at the end of array!!!\n", value);
  a->arr[a->length] = value;
  a->length++;
}

void Insert(struct Array *a, int index, int value) {
  printf("Insert value %d at the index %d\n", value, index);
  for (int i = a->length; i > index; i--) {
    a->arr[i] = a->arr[i - 1];
  }
  a->arr[index] = value;
  a->length++;
}

void Delete(struct Array *a, int index) {
  printf("Delete value at index: %d\n", index);
  for (int i = index; i < a->length; i++) {
    a->arr[i] = a->arr[i + 1];
  }
  a->length--;
}

int Linear_Search(struct Array *a, int value) {
  printf("Linear Search for value %d, return -1 if not found.\n", value);
  for (int i = 0; i < a->length; i++) {
    if (a->arr[i] == value) {
      printf("Found value %d at index %d\n", value, i);
      return i;
    }
  }
  printf("Not found value %d in array\n", value);
  return -1;
}

int Binary_Search(struct Array *a, int value) {
  printf("Binary Search for value: %d, return -1 if not found.\n", value);
  int low = 0;
  int high = a->length - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int mid_value = a->arr[mid];
    if (value == mid_value) {
      printf("Found value %d at index %d in array.\n", value, mid);
      return mid;
    } else if (value < mid_value) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  printf("Not found value %d in the array.\n", value);
  return -1;
}

int Binary_Search_Recursive(struct Array *a, int value, int low, int high) {
  if (low > high) {
    printf("Not found value %d in the array.\n", value);
    return -1;
  }
  int mid = (low + high) / 2;
  int mid_value = a->arr[mid];
  if (value == mid_value) {
    printf("Found value %d at index %d\n", value, mid);
    return mid;
  } else if (value < mid_value) {
    high = mid - 1;
  } else {
    low = mid + 1;
  }
  return Binary_Search_Recursive(a, value, low, high);
}

int Get(struct Array *a, int index) {
  printf("Get value at index: %d, return -1 if index is invalid.", index);
  if (index >= 0 && index < a->length) {
    printf("Index is valid, value : %d", a->arr[index]);
    return a->arr[index];
  }
  printf("Index is invalid");
  return -1;
}

int Set(struct Array *a, int index, int value) {
  printf("Set index %d to value %d", index, value);
  if (index >= 0 && index < a->length) {
    printf("Index is valid");
    a->arr[index] = value;
    return value;
  }
  printf("Index is invalid");
  return -1;
}

void Reverse(struct Array *a) {
  printf("Reverse array .\n");
  int *temp_arr = (int *)malloc(sizeof(int) * a->length);
  for (int i = 0; i < a->length; i++) {
    temp_arr[i] = a->arr[i];
  }
  for (int j = a->length - 1; j >= 0; j--) {
    a->arr[a->length - 1 - j] = temp_arr[j];
  }
  free(temp_arr);
  temp_arr = NULL;
}

void Swap(struct Array *a, int index1, int index2) {
  int temp = a->arr[index1];
  a->arr[index1] = a->arr[index2];
  a->arr[index2] = temp;
}

void Reverse_swap(struct Array *a) {
  printf("Reverse array using swap function.\n");
  int i = 0;
  int j = a->length - 1;
  while (i < j) {
    Swap(a, i, j);
    i++;
    j--;
  }
}

int main(int argc, char *argv[]) {
  struct Array a;
  a.length = 5;
  a.size = 10;
  a.arr = (int *)malloc(sizeof(int) * a.size);
  for (int i = 0; i < a.length; i++) {
    a.arr[i] = i;
  }
  Display(&a);

  // Append(&a, 20);
  // Display(&a);
  // Insert(&a, 5, 10);
  // Display(&a);
  // Delete(&a, 2);
  // Display(&a);
  // Linear_Search(&a, 20);
  // Linear_Search(&a, 50);
  // Binary_Search(&a, 20);
  // Binary_Search(&a, 50);
  // printf("Binary_Search_Recursive for value 20\n");
  // Binary_Search_Recursive(&a, 20, 0, a.length - 1);
  // printf("Binary_Search_Recursive for value 50\n");
  // Binary_Search_Recursive(&a, 50, 0, a.length - 1);
  // Reverse(&a);
  Reverse_swap(&a);
  Display(&a);
  return 0;
}

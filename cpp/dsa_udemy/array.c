#include <stdio.h>
struct Array {
  int *arr;
  int length;
  int size;
};

int main(int argc, char *argv[]) {
  struct Array a;
  printf("Enter the size of array: ");
  scanf("%d", &a.size);

    printf("Enter number of numbers : ");
    scanf("%d",&a.length);
    for(int i =0;i < a.length;i++){
        scanf("%d",&a.arr[i]);
    }
    for(int i =0;i < a.length;i++){
        printf("%d ",a.arr[i]);
    }
  return 0;
}

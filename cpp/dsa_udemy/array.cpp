#include <iostream>

int main(int argc, char *argv[]) { int *p = new int[5];
    int *temp = new int[10];
    delete [] p;
    p=temp;
    p = nullptr;

    int arr1[2][3];

    int *arr2[2];
    arr2[0] = new int[3];
    arr2[1] = new int[3];

    int **arr3;
    arr3 = new int*[2];
    arr3[0] = new int[3];
    arr3[1] = new int[3];
}

#define DAYS_OF_WEEK 7

enum days { MON, TUE, WEB, THU, FRI, SAT, SUN };
// MON gets 0, TUE get 1, ...

/*enum days {MON = 0, TUE, WED = 20, THU, FRI};*/
// TUE gets 1, THU gets 21

#include "myheader.h" // user headers
#include <stdlib.h>   // system libraries
#include <stdio.h>

// declare function in top of the files or in header file.
void funtion1();

// argc : number of args
// argv[0] : name of program, argv[1] : name of first parameter..
int main(int argc, char *argv[]) {
  int a = 100;
  // printf : "print formatted" print output
  printf("%d\n", a); // %d: integer

  // take input by "scanf"
  int input = 0;
  printf("%zu", sizeof(input));
  /*scanf("%d", &input);  // '&' is used to define the location where we want to
   * store the input value*/

  // Array
  // Array cần được khởi tạo với số phần từ cho trước
  int int_array[20];
  return EXIT_SUCCESS;
}

///////////////////////////////////////
/////////// Pointers //////////////////
///////////////////////////////////////

// có thể biến một biến global thành private với từ khóa "static", lúc này code
// ở file code khác không thể sử dụng biến này.
static int x = 0;

// sử dụng "typedef" để đặt biệt danh cho kiểu dữ liệu
typedef int my_int;
my_int int_var = 10;

// struct là một tập hợp các dữ liệu, các thành phần của nó được lưu trữ nối
// tiếp nhau, theo thứ tự như khi khai báo
struct Retangle {
  int width;
  int length;
};

void func_1(){
  struct Retangle my_rect = {3, 4};
  struct Retangle *ptr_to_Rect = &my_rect;
  
  // dereferencing
  (*ptr_to_Rect).width = 30;
  ptr_to_Rect->width = 40;    // better way with same effect
}

// sử dụng "typedef" và "struct"
typedef struct {
  int wid;
  int height;
} rec ;
rec r = {108, 20};
// với các struct lớn, có thể sử dụng Pointers để tránh việc copy toàn bộ struct vào fucntion.

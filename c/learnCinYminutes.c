#define DAYS_OF_WEEK 7

enum days { MON, TUE, WEB, THU, FRI, SAT, SUN };
// MON gets 0, TUE get 1, ...

enum days {MON = 0, TUE, WED = 20, THU, FRI};
// TUE gets 1, THU gets 21

#include "myheader.h" // user headers
#include <stdlib.h>   // system libraries

// declare function in top of the files or in header file.
void funtion1();

// argc : number of args
// argv[0] : name of program, argv[1] : name of first parameter..
int main(int argc, char *argv[]) {
  // printf : "print formatted" print output
  printf("%d\n", 0); // %d: integer

  // take input by "scanf"
  int input = 0;
  printf("%d", sizeof(input));
  /*scanf("%d", &input);  // '&' is used to define the location where we want to store the input value*/

  // Array
  // Array cần được khởi tạo với số phần từ cho trước
  int int_array[20];
  return EXIT_SUCCESS;
}

///////////////////////////////////////
/////////// Pointers //////////////////
///////////////////////////////////////



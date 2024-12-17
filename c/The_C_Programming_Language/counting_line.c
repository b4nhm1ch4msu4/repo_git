#include <stdio.h>

int main()
{
  long c;
  int count = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      ++count;
  }
  printf("%d\n",count);
  return 0;
}

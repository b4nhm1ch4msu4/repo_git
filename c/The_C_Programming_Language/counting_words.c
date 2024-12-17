#include <stdio.h>

#define IN 1;
#define OUT 0:

int main() {
  int c, nl, nw, nc, state;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {

      ++nl;
    }

    if (c == '\n' || c == '\t' || c == ' ') {
      state = OUT;
    } else if (state == OUT) {
      ++nw;
    }
  }
  return 0;
}

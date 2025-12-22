#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, nl, nw, nc, state;
  nl = nw = nc = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {

      ++nl;
    }

    if (c == '\n' || c == '\t' || c == ' ') {
      state = OUT;
    } else if (state == OUT) {
      ++nw;
      state = IN;
    }
  }
  return 0;
}

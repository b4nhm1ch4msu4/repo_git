int main() {
  int x = 10;
  int* ptr{};   // declare a __pointer__
  ptr = &x;     // assign the __address of__ x to ptr
  int& ref{x};  // ref is a __reference to__ x
  *ptr = 20;    // __dereference__ ptr, change x to 20
  ref = 30;     // Changes x to 30 via reference

  return 0;
}

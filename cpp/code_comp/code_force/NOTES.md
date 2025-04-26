```cpp
// toupper and tolower function
// char in CPP equal to int
#define toupper(c) (c < 'A' ? (c + 'A' - 'a') : c)
#define tolower(c) (c < 'a' ? (c + 'a' - 'A') : c)
```

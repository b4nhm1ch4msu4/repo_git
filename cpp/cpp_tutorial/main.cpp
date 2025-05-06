#include <iostream>

template <typename T>
class SmartPointer {
 private:
  T* m_pointer;

 public:
  SmartPointer(T* pointer = nullptr) : m_pointer(pointer) {}

  ~SmartPointer() { delete m_pointer; }

  T& operator*() { return *m_pointer; }
};

void print() {
  SmartPointer<int> sp(new int(5));
  if(*sp == 10) {
    return;
  }
}

int main(int argc, char* argv[]) {

  return 0;
}

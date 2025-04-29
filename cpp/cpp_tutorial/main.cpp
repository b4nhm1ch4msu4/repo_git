#include <cassert>
#include <iostream>
#include <ostream>

class IntArray {
 private:
  int* m_array{};
  int m_size{};

 public:
  IntArray(int size) {
    assert(size > 0);
    m_size = size;
    m_array = new int[size];
  }

  IntArray(const IntArray& other) { deep_copy(other); }

  ~IntArray() {
    delete[] m_array;
    m_array = nullptr;
  }

  void deep_copy(const IntArray& other) {
    delete[] m_array;
    m_size = other.m_size;
    m_array = new int[m_size];
    if (other.m_array) {
      for (int i = 0; i < m_size; i++) {
        m_array[i] = other.m_array[i];
      }
    } else {
      m_array = nullptr;
    }
  }

  friend std::ostream& operator<<(std::ostream& out, const IntArray& arr) {
    for (int i = 0; i < arr.m_size; i++) {
      out << arr.m_array[i] << " ";
    }
    return out;
  }

  int& operator[](int index) {
    assert(index >= 0 && index < m_size);
    return m_array[index];
  }

  IntArray& operator=(const IntArray& other) {
    if (this != &other) {
      deep_copy(other);
    }
    return *this;
  }
};

IntArray fillArray() {
  IntArray a(5);

  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

int main() {
  IntArray a{fillArray()};

  std::cout << a << '\n';

  auto& ref{a};  // we're using this reference to avoid compiler self-assignment errors
  a = ref;

  IntArray b(1);
  b = a;

  a[4] = 7;

  std::cout << b << '\n';

  return 0;
}

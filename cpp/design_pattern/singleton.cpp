#include <chrono>
#include <iostream>
#include <mutex>
#include <ratio>
#include <string>
#include <thread>

class Singleton {
protected:
  static Singleton *singleton_;
  static std::mutex mutex_;
  std::string value_;
  Singleton(const std::string value) : value_(value) {}

public:
  Singleton(Singleton &other) = delete;
  void operator=(const Singleton &) = delete;
  static Singleton *GetInstance(const std::string &value);
  std::string value() const { return value_; }
};

Singleton *Singleton::singleton_ = nullptr;
std::mutex Singleton::mutex_;

Singleton *Singleton::GetInstance(const std::string &value) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (singleton_ == nullptr) {
    singleton_ = new Singleton(value);
  }
  return singleton_;
}

void ThreadFoo() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton *singleton = Singleton::GetInstance("FOO");
  std::cout << singleton->value() << "\n";
}

void ThreadBar() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton *singleton = Singleton::GetInstance("BAR");
  std::cout << singleton->value() << "\n";
}

int main(int argc, char *argv[]) {
  std::thread t1(ThreadBar);
  std::thread t2(ThreadFoo);
  t1.join();
  t2.join();
  // Singleton *s1 = Singleton::GetInstance("foo");
  // Singleton *s2 = Singleton::GetInstance("bar");
  //
  // std::cout << "s1 value: " << s1->value() << "\n";
  // std::cout << "s2 value: " << s2->value() << "\n";
  return 0;
}

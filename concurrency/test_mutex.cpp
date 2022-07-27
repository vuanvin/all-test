#include <iostream>
#include <mutex>
#include <thread>

int v = 1;

void critical_section(int change_v) {
  static std::mutex mtx;
  std::lock_guard<std::mutex> lock(mtx);
}

int main() {
  std::thread t1(critical_section, 2), t2(critical_section, 3);
  t1.join();
  t2.join();
  std::cout << v << std::endl;
  return 0;
}
#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> shared_var(0);

void writer() {
  shared_var.store(1, std::memory_order_release); // 写操作，释放内存序
}

void reader() {
  while (!shared_var.load(std::memory_order_acquire)) { // 读操作，获取内存序
    // 等待 shared_var 变为 1
  }
  std::cout << "Reader sees shared_var as 1" << std::endl;
}

int main() {
  std::thread t1(writer);
  std::thread t2(reader);

  t1.join();
  t2.join();
  return 0;
}
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
void TestOderRelaxed2() {
  std::atomic<int> a{0};
  std::vector<int> v3, v4;
  std::thread t1([&a]() {
    for (int i = 0; i < 10; i += 2) {
      a.store(i, std::memory_order_relaxed);
    }
  });

  std::thread t2([&a]() {
    for (int i = 1; i < 10; i += 2)
      a.store(i, std::memory_order_relaxed);
  });

  std::thread t3([&v3, &a]() {
    for (int i = 0; i < 10; ++i)
      v3.push_back(a.load(std::memory_order_relaxed));
  });

  std::thread t4([&v4, &a]() {
    for (int i = 0; i < 10; ++i)
      v4.push_back(a.load(std::memory_order_relaxed));
  });

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  for (int i : v3) {
    std::cout << i << " ";
  }

  std::cout << std::endl;
  for (int i : v4) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main() {
  TestOderRelaxed2();
  return 0;
}
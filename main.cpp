#include <concepts>
#include <iostream>

template <std::integral T> void print(T value) {
  std::cout << "Integral value: " << value << std::endl;
}

template <typename T>
  requires(!std::integral<T>)
void print(T value) {
  std::cout << "Non-integral value: " << value << std::endl;
}

int main() {
  print(42);   // 输出：Integral value: 42
  print(3.14); // 输出：Non-integral value: 3.14
}
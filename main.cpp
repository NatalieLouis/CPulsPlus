#include <concepts>
#include <iostream>

// 定义一个概念，要求类型 T 是整数类型
template <typename T>
concept Integral = std::is_integral_v<T>;

// 仅当 T 满足 Integral 概念时启用
template <Integral T>
void print_type(T value)
{
    std::cout << "Integral type: " << value << std::endl;
}

int main()
{
    print_type(42); // 输出: Integral type: 42
    // print_type(3.14);   // 编译错误，不满足 Integral 概念
    return 0;
}
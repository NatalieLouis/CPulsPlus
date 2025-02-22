#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if_t<std::is_integral<T>::value, int>
baz(T x)
{
    std::cout << "Integral: " << x << std::endl;
    return x;
}

int main()
{
    std::cout << baz(10); // 正常工作
    // baz(3.14); // 编译错误，因为 T 不是整型
    return 0;
}

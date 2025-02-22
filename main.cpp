#include <iostream>
#include <type_traits>

template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
void bar(T x)
{
    std::cout << "Integral: " << x << std::endl;
}

int main()
{
    bar(10); // 正常工作
    // bar(3.14); // 编译错误，因为 T 不是整型
    return 0;
}

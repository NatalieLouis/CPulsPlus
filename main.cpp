#include <iostream>

template <typename T, typename U>
void testestt()
{
    std::cout << "Hello world" << std::endl;
}

template <typename T, int>
void testestt()
{
    std::cout << "Bye world" << std::endl;
}

int main()
{
    testestt<int, double>(); // 调用第一个模板函数
    testestt<int, 42>(); // 调用第二个模板函数  函数重载而不叫偏特化
    return 0;
}
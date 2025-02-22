#include <iostream>
#include <type_traits> // 注意是 type_traits 而不是 typetraits

// 原始模板定义，使用一个额外的参数进行 SFINAE
template <typename T, typename = void>
class HasFoo : public std::false_type {
};

// 偏特化：为具有成员函数 foo 的类型提供特化
template <typename T>
class HasFoo<T, std::void_t<decltype(&T::foo)>> : public std::true_type {
};

struct A {
    void foo() { }
};

struct B {
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << "HasFoo<A>::value: " << HasFoo<A>::value << std::endl; // 输出：true
    std::cout << "HasFoo<B>::value: " << HasFoo<B>::value << std::endl; // 输出：false
}

#include <iostream>
#include <type_traits>
#include <utility> // 包含 std::declval

// 原始模板定义
template <typename T, typename = void>
struct HasFoo : std::false_type { };

// 偏特化：检查类型 T 是否有成员函数 foo()
template <typename T>
struct HasFoo<T, std::void_t<decltype(std::declval<T>().foo())>> : std::true_type { };

// 测试类
struct A {
    int foo(int num) { return num; }
};

struct B { };

int main()
{
    std::cout << std::boolalpha;
    std::cout << "HasFoo<A>::value: " << HasFoo<A>::value << std::endl; // 输出：true
    std::cout << "HasFoo<B>::value: " << HasFoo<B>::value << std::endl; // 输出：false
    return 0;
}
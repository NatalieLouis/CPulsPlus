#include <iostream>
#include <type_traits>
#include <utility> // 包含 std::declval

// 原始模板定义
template <typename T, typename = void>
struct HasFoo : std::false_type { };

// 偏特化：检查类型 T 是否有成员函数 int foo(int)
template <typename T>
struct HasFoo<T, std::void_t<decltype(std::declval<T>().foo(std::declval<int>()))>> {
    static constexpr bool value = std::is_same<decltype(std::declval<T>().foo(std::declval<int>())), int>::value;
};

// 测试类
struct A {
    int foo(int num) { return num; } // 匹配 int foo(int)
};

struct B {
    void foo(int num) { } // 不匹配，返回类型不是 int
};

struct C {
    int foo(double num) { return static_cast<int>(num); } // 不匹配，参数类型不是 int
};

struct D {
    int foo() { return 42; } // 不匹配，参数数量不一致
};

// 辅助函数，用于检查参数类型是否严格为 int
template <typename T>
constexpr auto check_foo(int) -> decltype(std::declval<T>().foo(std::declval<int>()), std::true_type {})
{
    return {};
}

template <typename T>
constexpr std::false_type check_foo(...);

template <typename T>
struct HasFooStrict : decltype(check_foo<T>(0)) { };

int main()
{
    std::cout << std::boolalpha;
    std::cout << "HasFoo<A>::value: " << HasFoo<A>::value << std::endl; // 输出：true
    std::cout << "HasFoo<B>::value: " << HasFoo<B>::value << std::endl; // 输出：false
    std::cout << "HasFoo<C>::value: " << HasFoo<C>::value << std::endl; // 输出：true
    std::cout << "HasFoo<D>::value: " << HasFoo<D>::value << std::endl; // 输出：false

    std::cout << "HasFooStrict<A>::value: " << HasFooStrict<A>::value << std::endl; // 输出：true
    std::cout << "HasFooStrict<B>::value: " << HasFooStrict<B>::value << std::endl; // 输出：true
    std::cout << "HasFooStrict<C>::value: " << HasFooStrict<C>::value << std::endl; // 输出：true
    std::cout << "HasFooStrict<D>::value: " << HasFooStrict<D>::value << std::endl; // 输出：false
    return 0;
}
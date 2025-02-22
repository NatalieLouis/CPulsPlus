#include <concepts>
#include <iostream>
#include <type_traits>

// 定义一个概念，要求类型 T 具有 void foo()
template <typename T>
concept HasFoo = requires(T t) {
    { t.foo(std::declval<int>()) } -> std::same_as<int>;
};

// 仅当 T 满足 HasFoo 概念时启用
template <HasFoo T>
void call_foo(T& obj)
{
    obj.foo(3);
    std::cout << "foo() called." << std::endl;
}

class WithFoo {
public:
    int foo(double x)
    {
        std::cout << "WithFoo::foo()" << std::endl;
        return x;
    }
};

class WithoutFoo { };

int main()
{
    WithFoo wf;
    call_foo(wf); // 输出: WithFoo::foo()
                  //      foo() called.

    // WithoutFoo wf2;
    // call_foo(wf2); // 编译错误，不满足 HasFoo 概念
    return 0;
}
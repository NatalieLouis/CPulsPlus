#include <iostream>

// 原始模板定义
template <typename T>
class MyClass {
public:
    void print()
    {
        std::cout << "General template" << std::endl;
    }
};

// 偏特化：为所有指针类型提供特化实现
template <typename T>
class MyClass<T*> {
public:
    void print()
    {
        std::cout << "Specialized for pointer" << std::endl;
    }
};

int main()
{
    MyClass<int> obj1; // 使用原始模板
    MyClass<int*> obj2; // 使用偏特化实现

    obj1.print(); // 输出：General template
    obj2.print(); // 输出：Specialized for pointer
}
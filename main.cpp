#include <iostream>
#include <list>
#include <vector>

// 基本模板
template <typename T>
struct value_type_traits {
    using type = void; // 默认类型
};

// 特化模板，针对标准容器
template <typename T>
struct value_type_traits<std::vector<T>> {
    using type = T;
};

template <typename T>
struct value_type_traits<std::list<T>> {
    using type = T;
};

// 测试代码
int main()
{
    using VecType = std::vector<int>;
    using ValueType = value_type_traits<VecType>::type;

    std::cout << "VecType: " << typeid(VecType).name() << std::endl;
    std::cout << "ValueType: " << typeid(ValueType).name() << std::endl;

    return 0;
}
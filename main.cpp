#include <iostream>
#include <type_traits> // 用于测试

// 基本模板
template <typename T>
struct is_integral_type {
    static constexpr bool value = false;
};

// 特化模板，针对所有整数类型
template <>
struct is_integral_type<int> {
    static constexpr bool value = true;
};

template <>
struct is_integral_type<long> {
    static constexpr bool value = true;
};

template <>
struct is_integral_type<unsigned int> {
    static constexpr bool value = true;
};

template <>
struct is_integral_type<long long> {
    static constexpr bool value = true;
};

// 测试代码
int main()
{
    std::cout << std::boolalpha; // 打印布尔值为 true/false
    std::cout << "is_integral_type<int>: " << is_integral_type<int>::value << std::endl;
    std::cout << "is_integral_type<double>: " << is_integral_type<double>::value << std::endl;
    std::cout << "is_integral_type<unsigned int>: " << is_integral_type<unsigned int>::value << std::endl;
    return 0;
}
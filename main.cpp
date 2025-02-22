#include <iostream>
#include <list>
#include <type_traits>
#include <vector>

// SFINAE 检查成员函数
template <typename T, typename = void>
struct has_size_member : std::false_type { };

template <typename T>
struct has_size_member<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type { };

// 测试代码
int main()
{
    std::cout << std::boolalpha;
    std::cout << "has_size_member<std::vector<int>>: " << has_size_member<std::vector<int>>::value << std::endl; // true
    std::cout << "has_size_member<std::list<int>>: " << has_size_member<std::list<int>>::value << std::endl; // true
    std::cout << "has_size_member<int>: " << has_size_member<int>::value << std::endl; // false
    return 0;
}
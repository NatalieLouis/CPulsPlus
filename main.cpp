#include <iostream>
#include <string>
#include <type_traits>

// 通用类模板
template <typename T, typename Enable = void>
class Logger {
public:
    static void log(const T& value)
    {
        std::cout << "General Logger: " << value << std::endl;
    }
};

// 类模板偏特化：当 T 是指针类型
template <typename T>
class Logger<T, typename std::enable_if<std::is_pointer<T>::value>::type> {
public:
    static void log(T value)
    {
        if (value) {
            std::cout << "Pointer Logger: " << *value << std::endl;
        } else {
            std::cout << "Pointer Logger: nullptr" << std::endl;
        }
    }
};

// 类模板全特化：当 T 是 std::string
template <>
class Logger<std::string> {
public:
    static void log(const std::string& value)
    {
        std::cout << "String Logger: \"" << value << "\"" << std::endl;
    }
};

// 函数模板，用于递归调用 Logger::log
template <typename T>
void logOne(const T& value)
{
    Logger<T>::log(value);
}

// 使用模板折叠表达式实现多参数日志记录
template <typename... Args>
void logAll(const Args&... args)
{
    (logOne(args), ...); // 左折叠，调用 logOne 对每个参数进行日志记录
}

int main()
{
    int a = 10;
    double b = 3.14;
    std::string s = "Hello, World!";
    int* ptr = &a;
    double* pNull = nullptr;

    // 使用 Logger 类模板进行特化打印
    Logger<int>::log(a); // 输出：General Logger: 10
    Logger<double*>::log(pNull); // 输出：Pointer Logger: nullptr
    Logger<std::string>::log(s); // 输出：String Logger: "Hello, World!"

    std::cout << "\nLogging multiple parameters:" << std::endl;
    logAll(a, b, s, ptr, pNull);
    /*
    输出：
    General Logger: 10
    General Logger: 3.14
    String Logger: "Hello, World!"
    Pointer Logger: 10
    Pointer Logger: nullptr
    */

    return 0;
}
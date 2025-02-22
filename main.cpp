template <bool B, class T = void>
struct enable_if;

template <class T>
struct enable_if<true, T> {
    typedef T type;
};

template <typename T>
std::enable_if_t<条件, 返回类型> 函数名(参数列表);
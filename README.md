# cplusplusstandard_project
test c++ 11, 14, 17 new feature

Elegant C++, the ultimate C++
优雅的C++，最求极致的C++

std::unordered_map, std::unordered_set
基于哈希表的快速查找容器。
背后存储的是hash值，用于提高查找速度，但是原始值保持原有顺序

std::array
固定大小的安全数组替代原生数组。
使用at越界会抛出异常，at会判断是否越界，时候用[]越界行为不确定

std::tuple
std::tuple<int, double, string> mytuple(1, 2.2, “hello”);
std::get<0>(mytuple);
多元组结构。同时存储3个对象

static_assert

std::shared_timed_mutex
read/write lock, time out
读写锁，提高效率，支持超时判断

[[nodiscard]]
you should deal with my return value
必须处理我的返回值

[[deprecated]]
I will replace the old function step by step
我会一步一步替换我的旧函数

constexpr
I want to make sure it when compile rather than run
编译器确定，提高性能，极致优化

std::optional<int> a；
I can be value or not, it's clear now, i don't like nullptr, it's ugly
我可以有值或则无值，现在更加明确，不需要nullptr这种丑陋的方法

string_view
I am a temporary value, no memory, but i have length, it's easy to substr, at
明确我是一个空壳，我只是为了方便计算，我在开始就确定了指向哪个内存，长度是多少，不需要char*, int length两个变量表示了





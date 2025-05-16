#include "gtest/gtest.h"

struct TestStructC14
{
    int a;
    std::string b;
    double c;
    int d;
};


TEST(testcpp17, test_grammar)
{
    auto [x1, x2, x3, x4] = TestStructC14{1, "2x", 3.0, 0b1111};

    EXPECT_EQ(x1, 1);
    EXPECT_EQ(x2, "2x");
    EXPECT_EQ(x3, 3.0);
    EXPECT_EQ(x4, 0b1111);
    EXPECT_EQ(x4, 15);
    EXPECT_EQ(typeid(x2), typeid(std::string));
    EXPECT_EQ(typeid(x3), typeid(double));
    EXPECT_EQ(typeid(x4), typeid(int));
    EXPECT_EQ(typeid(x1), typeid(int));

    std::optional<int> x5 = std::nullopt;
    EXPECT_EQ(x5.has_value(), false);
    x5.emplace(1);
    EXPECT_EQ(x5.has_value(), true);
    EXPECT_EQ(x5.value(), 1);   

    std::vector v{1,2,3};
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);

   
    int a = 1;
    int b = 0b1111;
    EXPECT_TRUE(std::is_integral<decltype(a)>::value);
    EXPECT_TRUE((std::is_same<decltype(a), decltype(b)>::value));

    EXPECT_TRUE(std::is_integral<char>::value);
}
TEST(testcpp17, test_constexpr)
{
    std::optional<int> x1 = std::nullopt;
    EXPECT_FALSE(x1.has_value());
    x1.emplace(1);
    EXPECT_TRUE(x1.has_value());
    EXPECT_EQ(x1.value(), 1);
    
    std::variant<int, std::string> x2 = 1;
    EXPECT_EQ(std::get<int>(x2), 1);
    x2 = "123";
    EXPECT_EQ(std::get<std::string>(x2), "123");

    std::any a = 1;
    EXPECT_EQ(std::any_cast<int>(a), 1);
    EXPECT_TRUE(a.type() == typeid(int));
    try
    {
        std::any_cast<std::string>(a);
    }
    catch (const std::bad_any_cast& e)
    {
        auto msg = e.what();
        auto msg2 = "bad_any_cast";
        EXPECT_EQ(*msg, *msg2);
    }

    a = "123";
    EXPECT_EQ(std::any_cast<std::string>(a), "123");
    EXPECT_TRUE(a.type() == typeid(std::string));

    std::string s = "hello";
    std::string_view sv = s;
    EXPECT_EQ(sv.size(), 5);
    std::string_view sv2 = sv.substr(0, 2);
    EXPECT_EQ(sv2.size(), 2);
    EXPECT_EQ(s.data(), sv2.data());
}
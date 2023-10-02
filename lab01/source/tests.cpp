#include <gtest/gtest.h>
#include "child.hpp"

TEST(test01, sum41) {
    std::string s = "this website is for losers lol!";
    ASSERT_TRUE(sum(s) == 9);
}

TEST(test02, sum41) {
    std::string s = "aeiou";
    ASSERT_TRUE(sum(s) == 5);
}

TEST(test03, sum41) {
    std::string s = "bcdBCD";
    ASSERT_TRUE(sum(s) == 0);
}

TEST(test04, sum41) {
    std::string s = "a b c d e?";
    ASSERT_TRUE(sum(s) == 2);
}

TEST(test05, sum41) {
    std::string s = " ";
    ASSERT_TRUE(sum(s) == 0);
}

TEST(test06, sum41) {
    std::string s = "        ";
    ASSERT_TRUE(sum(s) == 0);
}

TEST(test07, sum41) {
    std::string s = "daniil";
    ASSERT_TRUE(sum(s) == 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

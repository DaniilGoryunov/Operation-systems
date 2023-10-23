#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "parent.hpp"

void TestParent(const std::string &src, const std::string &check, const std::string &str) {
    std::istringstream srcStream(src);
    std::streambuf* buf = std::cin.rdbuf(srcStream.rdbuf());

    Parent();

    std::ifstream in;
    in.open(str);
    std::string res;
    std::getline(in, res);
    in.close();

    ASSERT_EQ(res, check);    
}

TEST(test01, sum1) {
    std::string s = "file.txt 1 2 3 4 5";
    std::string check = "15";
    TestParent(s, check, "file.txt");
}

TEST(test01, sum2) {
    std::string s = "file1.txt 1 2 3 4";
    std::string check = "10";
    TestParent(s, check, "file1.txt");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

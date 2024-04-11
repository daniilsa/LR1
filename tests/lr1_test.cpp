#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>

// Подробнее https://google.github.io/googletest/reference/testing.html

// Тестовый класс
class ReplaceAndSumTest : public ::testing::Test {
protected:

    void TearDown() override {
        arr.clear();
        result.clear();
    }

    std::vector<int> arr;
    std::vector< std::pair<int, std::vector<int>>> result;
};

std::vector<int> generateOddArray(int size) {
    std::vector<int> array;
    int num = 1;
    for (int i = 0; i < size; ++i) 
    {
        array.push_back(num);
        num += 2; 
    }
    return array;
}


TEST_F(ReplaceAndSumTest, TestEmptyArray) {
    arr = {};
    result = { {0, {}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArraySize1) {
    arr = { 1 };
    result = { {1, {1}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}





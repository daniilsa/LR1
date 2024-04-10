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

TEST_F(ReplaceAndSumTest, EmptyArray) 
{
    arr = {};
    result = { {0, {}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, NoOddDigits) 
{
    arr = { 246, 802, 444 };
    result = { {1492, {246, 802, 444}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, AllOddDigits) {
    arr = { 135, 579, 753 };
    result = { {1467, {1467, 1467, 1467}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, MixedDigits) {
    arr = { 123, 456, 789, 321, 654 };
    result = { {2343, {123, 456, 789, 321, 654}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, SingleElementArray) {
    arr = { 5 };
    result = { {5, {5}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, NegativeNumbers) {
    arr = { -3, -7, 8, -9 };
    result = { {-11, {-11, -11, 8, -11}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, LargeNumbers) {
    arr = { 12345, 9876 };
    result = { {22221, {12345, 9876}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, AllZeroes) {
    arr = { 0, 0, 0, 0 };
    result = { {0, {0, 0, 0, 0}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, MixOfZeroesAndNonZeroes) {
    arr = { 0, 0, 3, 0, 5 };
    result = { {8, {8, 8, 8, 8, 8}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}



TEST_F(ReplaceAndSumTest, AllEvenDigits) {
    arr = { 246, 802, 444 };
    result = { {1492, {246, 802, 444}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}


TEST_F(ReplaceAndSumTest, NegativeAndPositiveNumbers) {
    arr = { -3, -7, 8, -9, 10 };
    result = { {-1, {-1, -1, 8, -1, 10}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}



TEST_F(ReplaceAndSumTest, MixedNumbersWithOddDigits) {
    arr = { 123, 456, 789, 321, 654 };
    result = { {2343, {123, 456, 789, 321, 654}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}



TEST_F(ReplaceAndSumTest, AllZeroesExceptOne) {
    arr = { 0, 0, 0, 0, 1 };
    result = { {1, {1, 1, 1, 1, 1}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, NegativeNumbersOnly) {
    arr = { -1, -2, -3, -4, -5 };
    result = { {-15, {-15, -2, -15, -4, -15}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, EmptyArrayTwice) {
    arr = {};
    result = { {0, {}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, OnlyOddDigitsFailed) {
    arr = { 135, 579, 753 };
    result = { {2265, {2265, 2265, 2265}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, MixedNumbersWithEvenDigitsFailed) {
    arr = { 234, 567, 890, 135, 246 };
    result = { {2072, {234, 2072, 2072, 2072, 246}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, RandomNumbersFailed) {
    arr = { 42, 17, 89, 1001 };
    result = { {1149, {42, 1149, 1149, 1149}} };
    EXPECT_EQ(replaceAndSum(arr), result[0]);
}
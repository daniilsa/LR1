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

std::vector<int> generateEvenArray(int size) {
    std::vector<int> array;
    int num = 2;
    for (int i = 0; i < size; ++i) {
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

// Тест на массив из 53 элементов
TEST_F(ReplaceAndSumTest, ArrayWith53Elements) {
    arr = generateOddArray(53);
    // Считаем сумму всех элементов массива
    int sum = 0;

    // Считаем сумму всех элементов массива
    for (int num : arr) {
        sum += num;
    }

    result = { {sum, {sum,sum,sum,sum,sum,sum,sum,sum,sum,sum, 21, 23, 25, 27, 29, sum,sum,sum,sum,sum,41, 43, 45, 47, 49, sum, sum, sum, sum, sum, 61, 63, 65, 67, 69, sum,sum,sum,sum,sum,81, 83, 85, 87, 89, sum, sum, sum, sum, sum, 101, 103, 105}} };
    ASSERT_EQ(replaceAndSum(arr), result[0]);
}

// Тест на массив из 105 элементов
TEST_F(ReplaceAndSumTest, ArrayWith105Elements) {
    arr = generateEvenArray(105);
    // Считаем сумму всех элементов массива
    int sum = 0;

    // Считаем сумму всех элементов массива
    for (int num : arr) {
        sum += num;
    }

    result = { {sum, arr} };
    ASSERT_EQ(replaceAndSum(arr), result[0]);
}




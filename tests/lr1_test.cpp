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



TEST_F(ReplaceAndSumTest, TestSingleElementArray) {
	arr = { 5 };
	result = { {5, {5}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayWithPositiveElements) {
	arr = { 3, 8, 2 };
	result = { {13, {13, 8, 2}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestEmptyArray) {
	arr = {};
	result = { {0, {}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayWithNegativeElements) {
	arr = { -4, -7, -2 };
	result = { {-13, {-4, -13, -2}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}


TEST_F(ReplaceAndSumTest, TestArrayWithNoOddDigits) {
	arr = { 24, 68, 42 };
	result = { {134, {24, 68, 42}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayWithOddDigits) {
	arr = { 24, 53, 42 };
	result = { {119, {24, 119, 42}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayWithZero) {
	arr = { 0, 0, 0 };
	result = { {0, {0, 0, 0}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayWithMixedDigits) {
	arr = { 24, 53, 42, 18 };
	result = { {137, {24, 137, 42, 18}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}



TEST_F(ReplaceAndSumTest, TestArrayWithSingleElementZero) {
	arr = { 0 };
	result = { {0, {0}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayWithSingleElementNegative) {
	arr = { -8 };
	result = { {-8, {-8}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayWithSingleElementPositive) {
	arr = { 12 };
	result = { {12, {12}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayWithMaxElements) {
	arr = { INT_MAX, INT_MAX, INT_MAX };
	result = { {INT_MAX * 3, {INT_MAX, INT_MAX, INT_MAX}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}



TEST_F(ReplaceAndSumTest, TestArrayMinimumBoundary) {
	arr = { INT_MIN };
	result = { {INT_MIN, {INT_MIN}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayMaximumBoundary) {
	arr = { INT_MAX };
	result = { {INT_MAX, {INT_MAX}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayOutsideMinimumBoundary) {
	arr = { INT_MIN - 1 };
	result = { {INT_MIN - 1, {INT_MIN - 1}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

TEST_F(ReplaceAndSumTest, TestArrayOutsideMaximumBoundary) {
	arr = { INT_MAX + 1 };
	result = { {INT_MAX + 1, {INT_MAX + 1}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}



// Тест с минимальным значением типа данных:
TEST_F(ReplaceAndSumTest, TestMinBoundary) {
	arr = { INT_MIN };
	result = { {INT_MIN, {INT_MIN}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

// Тест с элементом больше минимального значения:
TEST_F(ReplaceAndSumTest, TestBelowMaxBoundary) {
	arr = { INT_MIN + 1 };
	result = { {INT_MIN + 1, {INT_MIN + 1}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

// Тест с элементом равным 0:
TEST_F(ReplaceAndSumTest, TestZeroElement) {
	arr = { 0 };
	result = { {0, {0}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

//Тест с максимальным значением типа данных
TEST_F(ReplaceAndSumTest, TestMaxBoundary) {
	arr = { INT_MAX };
	result = { {INT_MAX, {INT_MAX}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

//Тест с элементом между минимальным и максимальным значениями
TEST_F(ReplaceAndSumTest, TestBetweenMinMaxBoundary2) {
	arr = { INT_MAX - 1 };
	result = { {INT_MAX - 1, {INT_MAX - 1}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

//Тест с отрицательным элементом
TEST_F(ReplaceAndSumTest, TestNegativeElement2) {
	arr = { -1 };
	result = { {-1, {-1}} };
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}


TEST_F(ReplaceAndSumTest, TestArrayLength1023) {
	arr = std::vector<int>(1023, 1);
	result = { {1023, std::vector<int>(1023, 1023)} }; // Ожидаемая сумма 1023, все элементы заменены на сумму
	EXPECT_EQ(replaceAndSum(arr), result[0]);
}

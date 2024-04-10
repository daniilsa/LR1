#include "lr1.h"


std::pair<int, std::vector<int>> replaceAndSum(const std::vector<int>& array) {
    int sum = 0;
    std::vector<int> new_array(array);

    // Считаем сумму всех элементов массива
    for (int num : array) {
        sum += num;
    }

    // Заменяем элементы, состоящие из нечетных цифр, на сумму всех элементов массива
    for (int& num : new_array) {
        if (hasOddDigits(num)) {
            num = sum;
        }
    }

    return std::make_pair(sum, new_array);
}

bool hasOddDigits(int num)
{
    num = abs(num);
    bool hasEvenDigit = false; // Флаг, отслеживающий наличие чётной цифры

    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 == 0) { // Если цифра чётная, устанавливаем флаг и выходим из цикла
            hasEvenDigit = true;
            break;
        }
        num /= 10;
    }

    return !hasEvenDigit; // Если не было найдено чётных цифр, возвращаем true, иначе false
}
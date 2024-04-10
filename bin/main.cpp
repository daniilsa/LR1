#include <iostream>
#include <vector>

#include <lib/lr1.h>

int main() 
{
    // Создаем массив целых чисел
    std::vector<int> array = generateOddArray(53);

    // Считаем сумму всех элементов массива
    int sum = 0;

    // Считаем сумму всех элементов массива
    for (int num : array) 
    {
        sum += num;
    }

    // Вызываем функцию replaceAndSum и сохраняем результат в переменной result
    std::pair<int, std::vector<int>> result = replaceAndSum(array);

    // Выводим сумму всех элементов массива
    std::cout << "Summ: " << result.first << std::endl;

    // Выводим новый массив
    std::cout << "New Array: ";
    for (int num : result.second) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

std::vector<int> generateOddArray(int size) {
    std::vector<int> array;
    int num = 1;
    for (int i = 0; i < size; ++i) {
        array.push_back(num);
        num += 2;
    }
    return array;
}


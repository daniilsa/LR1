#include <iostream>
#include <vector>

#include <lib/lr1.h>

int main() 
{
    // Создаем массив целых чисел
    std::vector<int> array = { 123, 456, 789, 321, 654 };

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
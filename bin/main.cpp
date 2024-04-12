#include <iostream>
#include <vector>

#include <lib/lr1.h>

int main() 
{
    std::vector<int> array;
    int numElements;

    // Вводим количество элементов массива
    std::cout << "Enter the number of elements: ";
    while (!(std::cin >> numElements) || numElements <= 0) {
        std::cout << "Invalid input. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Вводим элементы массива
    std::cout << "Enter " << numElements << " integers:\n";
    for (int i = 0; i < numElements; ++i) {
        int element;
        std::cout << "Element " << (i + 1) << ": ";
        while (!(std::cin >> element)) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        array.push_back(element);
    }

    // Вызываем функцию replaceAndSum и сохраняем результат в переменной result
    std::pair<int, std::vector<int>> result = replaceAndSum(array);

    // Выводим сумму всех элементов массива
    std::cout << "Sum: " << result.first << std::endl;

    // Выводим новый массив
    std::cout << "New Array: ";
    for (int num : result.second) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


#include <iostream>
#include <vector>

#include <lib/lr1.h>

int main() 
{
    // ������� ������ ����� �����
    std::vector<int> array = generateOddArray(53);

    // ������� ����� ���� ��������� �������
    int sum = 0;

    // ������� ����� ���� ��������� �������
    for (int num : array) 
    {
        sum += num;
    }

    // �������� ������� replaceAndSum � ��������� ��������� � ���������� result
    std::pair<int, std::vector<int>> result = replaceAndSum(array);

    // ������� ����� ���� ��������� �������
    std::cout << "Summ: " << result.first << std::endl;

    // ������� ����� ������
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


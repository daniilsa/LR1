#include <iostream>
#include <vector>

#include <lib/lr1.h>

int main() 
{
    // ������� ������ ����� �����
    std::vector<int> array = { 123, 456, 789, 321, 654 };

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
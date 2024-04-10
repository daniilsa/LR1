#include "lr1.h"


std::pair<int, std::vector<int>> replaceAndSum(const std::vector<int>& array) {
    int sum = 0;
    std::vector<int> new_array(array);

    // ������� ����� ���� ��������� �������
    for (int num : array) {
        sum += num;
    }

    // �������� ��������, ��������� �� �������� ����, �� ����� ���� ��������� �������
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
    bool hasEvenDigit = false; // ����, ������������� ������� ������ �����

    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 == 0) { // ���� ����� ������, ������������� ���� � ������� �� �����
            hasEvenDigit = true;
            break;
        }
        num /= 10;
    }

    return !hasEvenDigit; // ���� �� ���� ������� ������ ����, ���������� true, ����� false
}
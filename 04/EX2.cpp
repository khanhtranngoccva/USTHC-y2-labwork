//
// Created by khanh on 10/7/2022.
//
#include <cmath>
#include <iostream>

int digitSum(int number, int curSum=0);

/**
 * Compute the digit sum of an integer recursively.
 *
 * Pseudocode:
 * if (number == 0)
 *   return curSum
 * absoluteValue = abs(number)
 * curSum += absoluteValue % 10
 * return digitSum(absoluteValue / 10, curSum)
 *
 * Time complexity: O(n) with n being how many digits there are in the number, and we have to iterate over them all.
 * Space complexity: O(n) with n being how many digits there are, and requires up to n frames in the call stack.
 *
 * @param number The input number to compute the digit sum.
 * @return The digit sum of the number.
 */
int digitSum(int number, int curSum) {
    if (number == 0) {
        return curSum;
    }
    int absoluteValue = abs(number);
    curSum += absoluteValue % 10;
    return digitSum(absoluteValue / 10, curSum);
}

int main() {
    int n = 23854;
    std::cout << digitSum(n) << std::endl;
}
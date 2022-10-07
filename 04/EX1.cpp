//
// Created by khanh on 10/7/2022.
//
#include <cmath>
#include <iostream>

int digitSum(int number);

/**
 * Compute the digit sum of an integer iteratively.
 *
 * Pseudocode:
 * absolute = abs(number)
 * digitSum = 0
 * while absolute != 0
 *   digitSum += absolute %= 10
 *   absolute = floor(absolute / 10)
 * return digitSum
 *
 * Complexity: O(n) with n being how many digits there are in the number, and we have to iterate over them all.
 *
 * @param number The input number to compute the digit sum.
 * @return The digit sum of the number.
 */
int digitSum(int number) {
    int absolute = abs(number);
    int digitSum = 0;
    while (absolute != 0) {
        digitSum += absolute % 10;
        absolute /= 10;
    }
    return digitSum;
}

int main() {
    int n = 23854;
    std::cout << digitSum(n) << std::endl;
}
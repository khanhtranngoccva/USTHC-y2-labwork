//
// Created by Admin on 9/15/2022.
//
#include <iostream>

/**
 * Complexity: O(1).
 *
 * @param max Reference to the max variable. Will be replaced if a value v larger than max is found.
 * @param v The value to compare to the max variable's value.
 */
void findMax(int &max, int v) {
    if (v > max) {
        max = v;
    }
}

/**
 * Complexity: O(n).
 *
 * Pseudocode:
 * 1. Set curMax to a[0].
 * 2. for i = 1; i < len; step 1
 * 3.   findMax(curMax, a[i])
 * 4. return curMax
 *
 * @param a A pointer to an int array.
 * @param len The length of the integer array.
 * @returns The largest integer in the array.
 */
int findMaxOfArray(const int *a, int len) {
    int curMax = a[0];
    for (int i = 1; i < len; i++) {
        findMax(curMax, a[i]);
    }
    return curMax;
}


int main() {
    int array[] = {1, 9, 4, 6, 7};
    int result = findMaxOfArray(array, sizeof array / sizeof (int));
    std::cout << result << std::endl;
}
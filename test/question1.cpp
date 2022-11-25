//
// Created by khanh on 11/25/2022.
//
#include <iostream>
#include <cmath>

/**
 * Bubble sort function.
 *
 * Pseudocode:
 * for i = 0 to len - 2, step 1
 *     for j = i to len - 1, step 1
 *          if (arr[i] > arr[j])
 *               tmp = arr[i]
 *               arr[i] = arr[j]
 *               arr[j] = tmp
 *
 * Complexity: O(n ^ 2) because the number of operations are T(n) = 4 * (1 + 2 + ... + (n - 1)) = O(n ^ 2)
 *
 * @param arr
 * @param len
 */
void aSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i; j < len; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

/**
 * Check if a number is a prime number.
 *
 * Pseudocode:
 * n = abs(n)
 * if n <= 1 return false
 * for i = 2 to n - 1, step 1
 *     if n % i == 0
 *         return false
 * return true
 *
 * Complexity: O(n) because there is a linear loop from 2 to n - 1.
 *
 * @param n
 * @return
 */
bool isPrime(int n) {
    n = abs(n);
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * Pseudocode:
 * aSort(arr, len) // The aSort function bubble sorts the array. Pseudocode for this function is written above it.
 * if _position >= len - 1
 *     return
 * n1 = arr[_position]
 * n2 = arr[_position + 1]
 * if isPrime(n1) and isPrime(n2) and n1 + 2 == n2 // The isPrime function checks for primality of an integer. Pseudocode for this function is written above it.
 *     print(n1 + " " + n2)
 * searchTwinPrimes(arr, len, _position + 1)
 *
 * Complexity: O(n ^ 2) because there are 2 O(n) loops that checks for primality of a number nested within an O(n)
 * recursive loop from the beginning to the end of the array.
 *
 * @param arr The initial array. Will be mutated and sorted.
 * @param len The length of the array.
 * @param _position The starting _position of the recursive scan. Default is 0.
 */
void searchTwinPrimes(int *arr, int len, int _position = 0) {
    aSort(arr, len);
    if (_position >= len - 1) {
        return;
    }
    int n1 = arr[_position];
    int n2 = arr[_position + 1];
    if (isPrime(n1) && isPrime(n2) && n1 + 2 == n2) {
        std::cout << n1 << " " << n2 << std::endl;
    }
    searchTwinPrimes(arr, len, _position + 1);
}


/**
 * Main function declares and initializes a stack array and calls the searchTwinPrimes function.
 */
int main() {
    int initial[] = {3, 101, 96, 47, 41, 7, 65, 9, 13, 5, 79, 45, 39, 11, 43};
    searchTwinPrimes(initial, sizeof(initial) / sizeof(int));
}

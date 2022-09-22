//
// Created by Admin on 9/15/2022.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * Complexity: O(sqrt(n))
 *
 * Pseudocode:
 * if n == 1 or n == 0 return false
 * for i = 2; i <= sqrt(n); step 1
 *  if n % i == 0
 *   return false
 * return true
 * @param n The positive integer to check if it is prime.
 * @return 1 if number is prime, otherwise 0.
 */
bool is_prime(int n) {
    if (n == 1 || n == 0) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

/**
 * Complexity: O(n^3.5) or O(sqrt(n) * n ^ 3).
 *
 * Pseudocode:
 * for i = 2; i < n; step 1 [O(n)]
 *  for j = 2; j < n; step 1 [O(n)]
 *   for k = 2; k < n; step 1 [O(n)]
 *    if i * j * k == n and is_prime(i) and is_prime(j) and is_prime(k) and i != j and j != k and i != k [O(sqrt(n))]
 *      return true
 * return false
 *
 * @param n The integer to check whether it is sphenic or not.
 * @return 1 if number is sphenic, otherwise 0.
 */
bool is_sphenic(int n) {
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < n; j++) {
            for (int k = 2; k < n; k++) {
                if (i * j * k == n && i != j && j != k && i != k && is_prime(i) && is_prime(j) && is_prime(k)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int k = 42;
    printf("Is a sphenic number: %d\n", is_sphenic(k));
    return 0;
}
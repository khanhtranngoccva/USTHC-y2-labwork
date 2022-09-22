//
// Created by khanh on 9/16/2022.
//
#include <bits/stdc++.h>
using namespace std;

// Array with 1001 elements, supporting up to 1000.
bool primeCheckerArray[1001];

/**
 * Perform Eratosthenes's sieve on primeCheckerArray. Complexity: O(n ^ 2)
 *
 * Pseudocode:
 * Set everything in primeCheckerArray to true.
 * array_size = size of primeCheckerArray
 * primeCheckerArray[0] = false
 * primeCheckerArray[1] = false
 * for p = 0; p < array_size; step 1
 *  if primeCheckerArray[p]
 *   for i = 2 * p; i < array_size; i += p
 *    primeCheckerArray[i] = false
 */
void eratosthenes() {
    memset(primeCheckerArray, true, sizeof(primeCheckerArray));
    int array_size = sizeof(primeCheckerArray);
    primeCheckerArray[0] = false;
    primeCheckerArray[1] = false;
    for (int p = 0; p < array_size; p++) {
        if (primeCheckerArray[p]) {
            for (int i = p * 2; i < array_size; i += p) {
                primeCheckerArray[i] = false;
            }
        }
    }
}

/**
 * Complexity: O(1)
 *
 * @param n Integer to check if prime.
 * @return A boolean specifying the number's primality.
 */
bool is_prime(int n) {
    return primeCheckerArray[n];
}

/**
 * Complexity: O(n)
 *
 * Pseudocode:
 * fCount = 0
 * fIndex = 0
 * f[8] array declaration
 * for i = 1; i <= n; step 1
 *  if n % i == 0
 *   if pfCount <= 8
 *    fCount++
 *    f[fIndex] = i
 *    fIndex++
 *   else
 *    return false
 * pCount = 0
 * for i = 1; i < 8; i++
 *  if is_prime(f[i])
 *   pCount++
 * return pCount == 3
 *
 * @param n The integer to check whether it is sphenic or not. Must be non-negative and less than the length of primeCheckerArray.
 * @return 1 if number is sphenic, otherwise 0.
 */
bool is_sphenic(int n) {
    int f[8];
    int fCount = 0;
    int fIndex = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (fCount <= 8) {
                fCount++;
                f[fIndex] = i;
                fIndex++;
            } else {
                return false;
            }
        }
    }
    int pCount = 0;
    for (int i = 1; i < 8; i++) {
        if (is_prime(f[i])) {
            pCount++;
        }
    }
    return pCount == 3;
}

/**
 * Program complexity: O(n ^ 2)
 *
 * Pseudocode:
 * eratosthenes()
 * array_size = size of primeCheckerArray
 * input = -1
 * while not (0 <= input < array_size)
 *  print "Input a number and check if sphenic."
 *  input = (user_input)
 * result = is_sphenic(input)
 * print "Is a sphenic number: " + result
 * return 0
 */
int main() {
    eratosthenes();
    int array_size = sizeof(primeCheckerArray);
    int input = -1;
    while (!(0 <= input && input < array_size)) {
        cout << "Input a number and check if sphenic. ";
        cin >> input;
    }
    bool result = is_sphenic(input);
    cout << "Is a sphenic number: " << result << endl;
    return 0;
}



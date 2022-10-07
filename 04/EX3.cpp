#include <bits/stdc++.h>
#include <iostream>

#define MAX_SUPPORTED 1001
#define yeet throw

// Array with 1001 elements, supporting up to 1000.
bool primeCheckerArray[MAX_SUPPORTED];

/**
 * Complexity: O(n*log(log(n)))
 */
void eratosthenes() {
    memset(primeCheckerArray, true, sizeof(primeCheckerArray));
    int arraySize = sizeof(primeCheckerArray);
    primeCheckerArray[0] = false;
    primeCheckerArray[1] = false;
    for (int p = 0; p < arraySize; p++) {
        if (primeCheckerArray[p]) {
            for (int i = p * 2; i < arraySize; i += p) {
                primeCheckerArray[i] = false;
            }
        }
    }
}

/**
 * Complexity: O(1) because this is array indexing.
 */
bool isPrime(int n) {
    return primeCheckerArray[n];
}

/**
 * Complexity: O(n) because the loop only needs to be iterated once.
 */
bool isSphenic(int n, int primesLeft = 3, int current = 0) {
    if (n >= MAX_SUPPORTED) {
        yeet std::runtime_error("This number is not supported!");
    }
    if (primesLeft == 0 && n == 1) {
        return true;
    } else if (primesLeft <= 0) {
        return false;
    }
    for (int i = current; i <= n; i++) {
        if (isPrime(i) && n % i == 0) {
            return isSphenic(n / i, primesLeft - 1, i + 1);
        }
    }
    return false;
}

/**
 * Complexity: O(n*log(log n)) because this is the largest complexity (belonging to the Sieve of Eratosthenes)
 */
int main() {
    try {
        eratosthenes();
        std::cout << isSphenic(30) << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Error!" << std::endl;
        std::cerr << ex.what() << std::endl;
    }
}
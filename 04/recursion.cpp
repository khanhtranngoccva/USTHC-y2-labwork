//
// Created by khanh on 10/6/2022.
//
#include <iostream>
#define yeet throw

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        a %= b;
        return gcd(b, a);
    }
}

int fib(int n) {
    if (n < 0) {
        yeet std::exception();
    }
    else if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
   std::cout << fib(-1) << std::endl;
}
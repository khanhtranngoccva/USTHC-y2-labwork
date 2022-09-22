#include <cstdlib>
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

typedef struct Polynomial {
    int maxTerms;
    long double *terms;
} Polynomial;

Polynomial createPolynomial(int maxTerms) {
    Polynomial newPolynomial;
    size_t allocatedSize = maxTerms * sizeof (long double);
    newPolynomial.maxTerms = maxTerms;
    newPolynomial.terms = (long double *) malloc(allocatedSize);
    memset(newPolynomial.terms, 0, allocatedSize);
    return newPolynomial;
}

Polynomial setTerm(Polynomial &polynomial, int degree, long double coefficient) {
    if (degree < 0 || degree >= polynomial.maxTerms) {
        std::cerr << "Degree out of bounds!" << std::endl;
    } else {
        polynomial.terms[degree] = coefficient;
    }
    return polynomial;
}

Polynomial removeTerm(Polynomial &polynomial, int degree) {
    if (degree < 0 || degree >= polynomial.maxTerms) {
        std::cerr << "Degree out of bounds!" << std::endl;
    } else {
        polynomial.terms[degree] = 0;
    }
    return polynomial;
}

void printPolynomial(Polynomial &polynomial) {
    bool isZeroOnly = true;
    bool isFirstTerm = true;
    for (int i = 0; i < polynomial.maxTerms; i++) {
        float curValue = polynomial.terms[i];
        if (curValue != 0) {
            isZeroOnly = false;
            if (!isFirstTerm) {
                if (curValue < 0) {
                    std::cout << " - ";
                } else {
                    std::cout << " + ";
                }
            }
            std::cout << curValue;
            if (i == 1) {
                std::cout << "x";
            } else if (i > 1) {
                std::cout << "x^" << i;
            }
            isFirstTerm = false;
        }
    }
    if (isZeroOnly) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << std::endl;
    }
}

long double computePolynomial(Polynomial &polynomial, long double x) {
    long double sum = 0;
    for (int i = 0; i < polynomial.maxTerms; i++) {
        sum += polynomial.terms[i] * powl(x, i);
    }
    return sum;
}

int main() {
    Polynomial y = createPolynomial(5);
    setTerm(y, 0, 2);
    setTerm(y, 1, 3);
    setTerm(y, 2, 1);
    printPolynomial(y);
    std::cout << computePolynomial(y, 5) << std::endl;
    return 0;
}
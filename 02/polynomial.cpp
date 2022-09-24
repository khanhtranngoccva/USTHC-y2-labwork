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
    size_t allocatedSize = maxTerms * sizeof(long double);
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
    for (int i = polynomial.maxTerms - 1; i >= 0; i--) {
        long double curValue = polynomial.terms[i];
        if (curValue != 0) {
            isZeroOnly = false;
            if (!isFirstTerm) {
                if (curValue < 0) {
                    std::cout << " - ";
                } else {
                    std::cout << " + ";
                }
            } else if (curValue < 0) {
                std::cout << "-";
            }
            if ((curValue == 1 || curValue == -1) && i >= 1) {

            } else {
                if (curValue < 0) {
                    std::cout << -curValue;
                } else {
                    std::cout << curValue;
                }
            }
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
    Polynomial p = createPolynomial(5);

    for (int x = -2; x <= 2; x++) {
        for (int y = -2; y <= 2; y++) {
            for (int z = -2; z <= 2; z++) {
                setTerm(p, 0, x);
                setTerm(p, 1, y);
                setTerm(p, 2, z);
                printPolynomial(p);
            }
        }
    }
    return 0;
}
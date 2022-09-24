#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct Term {
    long double coefficient;
    int degree;
} Term;

typedef struct Polynomial {
    int maxTerms;
    int termCount;
    Term *terms;
} Polynomial;

Term createTerm(long double coefficient, int degree) {
    Term newTerm;
    newTerm.coefficient = coefficient;
    newTerm.degree = degree;
    return newTerm;
}

Polynomial createPolynomial(int maxTerms) {
    Polynomial newPolynomial;
    newPolynomial.maxTerms = maxTerms;
    newPolynomial.termCount = 0;
    newPolynomial.terms = (Term *) calloc(maxTerms, sizeof(Term));
    return newPolynomial;
};

int getTermCount(Polynomial *polynomial) {
    return polynomial->termCount;
}

Polynomial *addTerm_(Polynomial *polynomial, Term term) {
    if (polynomial->termCount >= polynomial->maxTerms) {
        fprintf(stderr, "The polynomial cannot fill in any more terms!");
        return polynomial;
    }
    for (int i = 0; i < getTermCount(polynomial); i++) {
        Term *candidateTerm = &polynomial->terms[i];
        if (candidateTerm->degree == term.degree) {
            candidateTerm->coefficient += term.coefficient;
            return polynomial;
        }
    }
    polynomial->terms[getTermCount(polynomial)] = term;
    polynomial->termCount++;
    return polynomial;
};

Polynomial *addTerm(Polynomial *polynomial, long double coefficient, int degree) {
    Term newTerm = createTerm(coefficient, degree);
    return addTerm_(polynomial, newTerm);
};


Polynomial *removeTerm(Polynomial *polynomial, int degree) {
    if (polynomial->termCount == 0) {
        fprintf(stderr, "The polynomial is already empty!");
        return polynomial;
    }
    for (int i = 0; i < getTermCount(polynomial); i++) {
        Term *candidateTerm = &polynomial->terms[i];
        if (candidateTerm->degree == degree) {
            for (int j = i; j < getTermCount(polynomial) - 1; j++) {
                polynomial->terms[j] = polynomial->terms[j + 1];
            }
            polynomial->termCount--;
            return polynomial;
        }
    }
    fprintf(stderr, "The polynomial does not have a term of that degree!");
    return polynomial;
};

void verbosePrintPolynomial(Polynomial *polynomial) {
    for (int i = 0; i < getTermCount(polynomial); i++) {
        Term *curTerm = &(polynomial->terms[i]);
        printf("Term %d: Degree: %d Coefficient: %Lf\n", i, curTerm->degree, curTerm->coefficient);
    }
}

void printPolynomial(Polynomial *polynomial) {
    bool isZeroOnly = true;
    bool isFirstTerm = true;
    for (int i = 0; i < polynomial->termCount; i++) {
        Term* curTerm = &polynomial->terms[i];
        long double curValue = curTerm -> coefficient;
        int curDegree = curTerm -> degree;
        if (curValue != 0) {
            isZeroOnly = false;
            if (!isFirstTerm) {
                if (curValue < 0) {
                    printf(" - ");
                } else {
                    printf(" + ");
                }
            } else if (curValue < 0) {
                printf("-");
            }
            if ((curValue == 1 || curValue == -1) && curDegree >= 1) {
            } else {
                int intConversion = (int) curValue;
                if (intConversion == curValue) {
                    if (curValue < 0) {
                        printf("%d", -intConversion);
                    } else {
                        printf("%d", intConversion);
                    }
                } else {
                    if (curValue < 0) {
                        printf("%Lf", -curValue);
                    } else {
                        printf("%Lf", curValue);
                    }
                }
            }
            if (curDegree == 1) {
                printf("x");
            } else if (curDegree > 1) {
                printf("x^%d", curDegree);
            }
            isFirstTerm = false;
        }
    }
    if (isZeroOnly) {
        printf("0\n");
    } else {
        printf("\n");
    }
}

long double evalPolynomial(Polynomial *polynomial, long double x) {
    long double y = 0;
    for (int i = 0; i < getTermCount(polynomial); i++) {
        Term *curTerm = &(polynomial->terms[i]);
        y += curTerm->coefficient * powl(x, curTerm->degree);
    }
    return y;
}

int main() {
    Polynomial p = createPolynomial(20);
    addTerm(&p, 20, 3);
    addTerm(&p, 1.5, 2);
    printPolynomial(&p);
    printf("Polynomial eval: %Lf\n", evalPolynomial(&p, 5));
    return 0;
}
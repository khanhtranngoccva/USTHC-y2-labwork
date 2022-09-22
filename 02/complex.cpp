#include <iostream>

struct complex {
    float real;
    float imaginary;
};

complex createComplex(float real, float imaginary) {
    complex newComplexNumber;
    newComplexNumber.real = real;
    newComplexNumber.imaginary = imaginary;
    return newComplexNumber;
}

complex addComplex(complex a, complex b) {
    return createComplex(a.real + b.real, a.imaginary + b.imaginary);
}

float abs(float arg) {
    return arg < 0 ? -arg : arg;
}

void printComplex(complex arg) {
    if (arg.imaginary < 0) {
        std::cout << arg.real << " - " << abs(arg.imaginary) << "i" << std::endl;
    } else {
        std::cout << arg.real << " + " << arg.imaginary << "i" << std::endl;
    }
}

int main() {
    complex x = createComplex(1, 2);
    complex y = createComplex(3, -4);
    complex z = addComplex(x, y);
    printComplex(z);
    return 0;
}
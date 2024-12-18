#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

void subtractComplex(Complex *c1, Complex *c2, Complex *result) {
    result->real = c1->real - c2->real;
    result->imag = c1->imag - c2->imag;
}

void multiplyComplex(Complex *c1, Complex *c2, Complex *result) {
    result->real = c1->real * c2->real - c1->imag * c2->imag;
    result->imag = c1->real * c2->imag + c1->imag * c2->real;
}

int main() {

    Complex c1 = {3.0, 2.0};
    Complex c2 = {1.0, 7.0};

    Complex sum = addComplex(c1, c2);
    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);

    Complex difference;
    subtractComplex(&c1, &c2, &difference);
    printf("Difference: %.2f + %.2fi\n", difference.real, difference.imag);

    Complex product;
    multiplyComplex(&c1, &c2, &product);
    printf("Product: %.2f + %.2fi\n", product.real, product.imag);

    return 0;
}
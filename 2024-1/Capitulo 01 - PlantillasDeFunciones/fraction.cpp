
#include "fraction.h"

// máximo común denominador
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

// simplificación de la matriz
void simplify(struct Fraction &f) {
    int divisor = gcd(f.numerator, f.denominator);
    f.numerator /= divisor;
    f.denominator /= divisor;
}
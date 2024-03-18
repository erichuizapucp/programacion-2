#include "myfunctions.h"

int add(int a) {
    return a + 10;
}

int add(int a, int b) {
    return a + b;
}

int add(int* a) {
    *a += 10;
}

int multiply(int a, int b) {
    return a * b;
}
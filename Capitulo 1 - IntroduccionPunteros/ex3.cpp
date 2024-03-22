// pass pointers to functions

// incorrect
void addTwoNumbers1(int a, int b, int c) {
    c = a + b;
}

// correct
void addTwoNumbers2(int *a, int *b, int *c) {
    *c = *a + *b;
}

void updatePointerAddress(int *&a) {
    *a = 87;
    delete a;
    a = new int;
    
    *a = 1010;
}
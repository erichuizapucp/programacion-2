#include <iostream>

using namespace std;

int main() {
    int a = 3;
    int b = 75;
    int c = a + b;

    int* p = &c;

    cout << *p << endl;
    *p = 100;
    cout << c << endl;

    int* pp = new int(5);
    delete pp;
    pp = new int(10);
    delete pp;

    return 0;
}

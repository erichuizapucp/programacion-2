#include <iostream>

using namespace std;

int main() {
    int* a = new int(8);
    void* v = a;

    cout << *(int*)v << endl;

    delete a;

    void** vv = new void*[2];
    vv[0] = new int(10);
    vv[1] = new char*[30];

    int* pp = (int*)vv[0];
    delete pp;

    delete[] vv;

    return 0;
}
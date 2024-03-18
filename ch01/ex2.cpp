#include <cstdlib>
#include <iostream>

using namespace std;

void arrayWithoutPointers() {
    int nums[10];
    
    for (int index = 0; index < 10; index ++) {
        nums[index] = index;
    }
    
    for (int index = 0; index < 10; index++) {
        cout << nums[index] << "\n";
    }
}

void arrayWithPointers() {
    int* nums = new int[10];  // it allocates 10 consecutive integers, 
                              // it is the equivalent to int nums[10]
    
    for (int index = 0; index < 10; index++) {
        nums[index] = index;
    }
    
    for (int index = 0; index < 10; index++) {
        cout << nums[index] << "\n";
    }
    
    delete[] nums;
}

void arrayWithPointers2() {
    int nums[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    int* pnums = nums; // always points to the first array element
    
    for (int index = 0; index < 10; index++) {
        cout << *pnums << "\n";
        pnums++;
    }
}

void arrayWithPointers3() {
    int* nums = new int[10];  // it allocates 10 consecutive integers, 
                              // it is the equivalent to int nums[10]
    
    for (int index = 0; index < 10; index++) {
        *nums = index;
        nums++;
    }
    
    nums -= 10;
    
    for (int index = 0; index < 10; index++) {
        cout << *(nums + index) << "\n";
    }
    
    delete[] nums;
}

void printArray(int* array) {
    for (int index = 0; index < 5; index++) {
        cout << *(array + index) << endl;
    }
}
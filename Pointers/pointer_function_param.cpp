#include <iostream>
using namespace std;

/*
❓ Question:
Pass pointer to function and increment value inside it.
*/

void increment(int* ptr) {
    (*ptr)++;
}

int main() {
    int num = 7;
    increment(&num);
    cout << "After increment: " << num << endl;
    return 0;
}

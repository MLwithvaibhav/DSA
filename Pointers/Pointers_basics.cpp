#include <iostream>
using namespace std;

/*
❓ Question:
Create an integer variable. Declare a pointer to it and print:
- The address of the variable
- The value using pointer
*/

int main() {
    int a = 10;
    int* p = &a;

    cout << "Address of a: " << &a << endl;
    cout << "Address using pointer: " << p << endl;
    cout << "Value using pointer: " << *p << endl;

    return 0;
}

#include <iostream>
using namespace std;

/*
❓ Question:
Demonstrate pointer to pointer (double pointer).
*/

int main() {
    int x = 42;
    int* p = &x;
    int** pp = &p;

    cout << "Value of x: " << x << endl;
    cout << "Using *p: " << *p << endl;
    cout << "Using **pp: " << **pp << endl;

    return 0;
}

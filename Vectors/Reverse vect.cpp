#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
❓ Question:
Reverse a vector and print it.
*/

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    reverse(v.begin(), v.end());

    cout << "Reversed Vector: ";
    for (int x : v)
        cout << x << " ";

    return 0;
}

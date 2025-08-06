#include <iostream>
#include <vector>
using namespace std;

/*
❓ Question:
Given a vector of integers, find and print the sum of all elements.
*/

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    int sum = 0;

    for (int x : v)
        sum += x;

    cout << "Sum of elements = " << sum << endl;

    return 0;
}

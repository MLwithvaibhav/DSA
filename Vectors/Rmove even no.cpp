#include <iostream>
#include <vector>
using namespace std;

/*
❓ Question:
Remove all even numbers from a vector.
*/

int main() {
    vector<int> v = {1, 4, 5, 6, 9, 10};
    vector<int> result;

    for (int x : v) {
        if (x % 2 != 0)
            result.push_back(x);
    }

    cout << "Vector after removing even numbers: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}

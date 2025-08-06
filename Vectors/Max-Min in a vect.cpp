#include <iostream>
#include <vector>
using namespace std;

/*
❓ Question:
Find the maximum and minimum element in a vector.
*/

int main() {
    vector<int> v = {9, 3, 12, 4, 7};

    int maxVal = v[0], minVal = v[0];

    for (int x : v) {
        if (x > maxVal) maxVal = x;
        if (x < minVal) minVal = x;
    }

    cout << "Max = " << maxVal << ", Min = " << minVal << endl;

    return 0;
}

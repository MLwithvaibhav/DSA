// 🧠 Problem: Sum of All Elements in Array
// 🧾 Description: Given an array, return the sum of all elements.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << "Sum: " << sum << endl;
    return 0;
}

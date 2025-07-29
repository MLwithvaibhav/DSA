// 🔍 Linear Search without function (C++)
// 📌 Question:
// Given an array of integers and a target value, find the index of the target using linear search.
// If not found, print -1.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 25, 3, 7, 12, 50};  // 🧾 Sample array
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    int index = -1;  // ❌ Initially assume target is not found

    // 🔁 Linear search logic
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

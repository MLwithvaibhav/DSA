// ✅ Topic: Arrays
// ✅ Question: Check if the Array is Sorted in Non-Decreasing Order

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false; // Found a pair which is not in order
        }
    }
    return true; // No unordered pair found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Try changing this to unsorted to test
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, size)) {
        cout << "The array is sorted in non-decreasing order." << endl;
    } else {
        cout << "The array is NOT sorted." << endl;
    }

    return 0;
}

// ✅ Topic: Arrays
// 🔍 Question: Find the Smallest Element in an Array

#include <iostream>
using namespace std;

int findSmallest(int arr[], int size) {
    int minElement = arr[0]; // Assume first element is the smallest

    for (int i = 1; i < size; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i]; // Update if smaller element found
        }
    }

    return minElement;
}

int main() {
    int arr[] = {5, 2, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int smallest = findSmallest(arr, size);

    cout << "Smallest element in the array: " << smallest << endl;

    return 0;
}

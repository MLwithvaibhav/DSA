// ✅ Topic: Arrays
// 📋 Question: Copy One Array to Another Array (Without Function)

#include <iostream>
using namespace std;

int main() {
    int arr1[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[size]; // Copy will be stored here

    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i]; // Copying each element
    }

    cout << "Copied array: ";
    for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}

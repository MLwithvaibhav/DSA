// ✅ Topic: Arrays
// 🔢 Question: Count Even and Odd Numbers in an Array

#include <iostream>
using namespace std;

void countEvenOdd(int arr[], int size) {
    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    cout << "Even numbers count: " << evenCount << endl;
    cout << "Odd numbers count: " << oddCount << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr)/sizeof(arr[0]);

    countEvenOdd(arr,size);

    return 0;
}
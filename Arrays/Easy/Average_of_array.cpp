// ✅ Topic: Arrays
// 📊 Question: Calculate the Average of Array Elements

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i]; // Adding each element to sum
    }

    float average = (float)sum / size;

    cout << "Average of array elements: " << average << endl;

    return 0;
}

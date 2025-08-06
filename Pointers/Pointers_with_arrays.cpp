#include <iostream>
using namespace std;

/*
❓ Question:
Given an array, use pointer arithmetic to print all elements.
*/

int main() {
    int arr[] = {5, 10, 15, 20};
    int* ptr = arr;

    for (int i = 0; i < 4; i++)
        cout << *(ptr + i) << " ";

    return 0;
}

/*
🧩 Problem: Sort an array using Bubble Sort

Given an array of integers, sort the array in ascending order using the Bubble Sort algorithm.

🧠 Approach:

1. Repeatedly traverse the array.
2. Compare adjacent elements and **swap** them if they are in the wrong order.
3. After each pass, the largest element "bubbles up" to its correct position.
4. Optimization: If no swaps are made in a pass, the array is already sorted (early stopping).

💡 Bubble Sort Facts:

- It is a comparison-based algorithm.
- Stable sort (doesn’t change the relative order of equal elements).
- Best case time complexity: O(n) → when array is already sorted.
- Worst/Average case time complexity: O(n^2)
- Space complexity: O(1) (in-place sorting)
*/


#include <iostream>
using namespace std;


// 🔁 Bubble Sort function
void bubbleSort(int arr[], int n) { // O(n^2)
    for(int i = 0; i < n - 1; i++) {
        bool isSwap = false;

        // Last i elements are already in place
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if(!isSwap) {
            // Array is already sorted
            return;
        }
    }
}


// 🔁 Function to print the array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// 🔰 Main function
int main() {
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}


/*
🧪 Dry Run:

Input: arr = {4, 1, 5, 2, 3}

Pass 1:
    Compare 4 & 1 → swap → {1, 4, 5, 2, 3}
    Compare 4 & 5 → ok
    Compare 5 & 2 → swap → {1, 4, 2, 5, 3}
    Compare 5 & 3 → swap → {1, 4, 2, 3, 5}

Pass 2:
    Compare 1 & 4 → ok
    Compare 4 & 2 → swap → {1, 2, 4, 3, 5}
    Compare 4 & 3 → swap → {1, 2, 3, 4, 5}

Pass 3:
    Compare 1 & 2 → ok
    Compare 2 & 3 → ok
    Compare 3 & 4 → ok → No swap made → Early stop ✅

Final Output: 1 2 3 4 5
*/

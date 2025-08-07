/*
🧩 Problem: Sort an array using Selection Sort

Given an array of integers, sort it in ascending order using the **Selection Sort** algorithm.

🧠 Approach:

1. Divide the array into two parts: **sorted** and **unsorted**.
2. Repeatedly select the **smallest element** from the unsorted part and place it at the beginning.
3. Keep growing the sorted part one element at a time.

💡 Selection Sort Facts (from API-level knowledge):

- Comparison-based sorting algorithm.
- **Not stable** by default.
- Performs well on small arrays.
- **In-place** algorithm (uses constant extra space).
- Time Complexity:
  - Best Case: O(n²)
  - Average Case: O(n²)
  - Worst Case: O(n²)
- Space Complexity: O(1)
- Selection sort makes **minimum number of swaps** compared to bubble/insertion sort.

👎 Downside:
- Even if array is sorted, still takes O(n²) time.
*/


#include <iostream>
using namespace std;


// 🔁 Selection Sort implementation
void selectionSort(int arr[], int n) { // O(n^2)
    for(int i = 0; i < n - 1; i++) {
        int smallestIdx = i; // Unsorted part starting index

        // Find the index of the smallest element in the remaining unsorted array
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[smallestIdx]) {
                smallestIdx = j;
            }
        }

        // Swap the found minimum element with the first element of unsorted part
        swap(arr[i], arr[smallestIdx]);
    }
}


// 🔁 Print array function
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

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}


/*
🧪 Dry Run:

Input: {4, 1, 5, 2, 3}

Pass 1: smallest = 1 → swap with 4 → [1, 4, 5, 2, 3]
Pass 2: smallest = 2 → swap with 4 → [1, 2, 5, 4, 3]
Pass 3: smallest = 3 → swap with 5 → [1, 2, 3, 4, 5]
Pass 4: Already in place → [1, 2, 3, 4, 5]

Sorted Output: 1 2 3 4 5
*/

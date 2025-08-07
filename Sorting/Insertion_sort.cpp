/*
🧩 Problem: Sort an array using Insertion Sort

Given an array of integers, sort the array in ascending order using the **Insertion Sort** algorithm.

🧠 Approach:

1. Consider the first element as sorted.
2. Take the next element (called `curr`) and insert it into its correct position in the sorted part.
3. Keep shifting larger elements to the right to make space for insertion.
4. Repeat until the array is sorted.

💡 Insertion Sort Facts (from API knowledge):

- Intuitive & easy-to-implement sorting method.
- **Stable sort**: Does not change the relative order of equal elements.
- Works well on small datasets and partially sorted arrays.
- Often used in hybrid sorting algorithms (e.g., Timsort in Python/Java).
- In-place algorithm → No extra space used.

⏱ Time Complexity:
- Best Case: O(n) → when array is already sorted
- Average/Worst Case: O(n²)
- Space Complexity: O(1)

👑 Advantage over Selection/Bubble:
- Efficient for nearly sorted arrays
- Fewer swaps (shifts are cheaper than swaps)
*/


#include <iostream>
using namespace std;


// 🔁 Insertion Sort implementation
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        // Shift elements greater than curr to the right
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        // Insert curr in the correct position
        arr[prev + 1] = curr;
    }
}


// 🔁 Print the array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// 🔰 Main Function
int main() {
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}


/*
🧪 Dry Run:

Input: {4, 1, 5, 2, 3}

i = 1 → curr = 1 → shift 4 → insert at index 0 → [1, 4, 5, 2, 3]
i = 2 → curr = 5 → already in place → [1, 4, 5, 2, 3]
i = 3 → curr = 2 → shift 5, 4 → insert at index 1 → [1, 2, 4, 5, 3]
i = 4 → curr = 3 → shift 5, 4 → insert at index 2 → [1, 2, 3, 4, 5]

Final Sorted Array: 1 2 3 4 5 ✅
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // 💬 Question:
    // Given an array of integers `A`, find the next lexicographically greater permutation of numbers.
    // If no such permutation exists, rearrange it as the lowest possible order (i.e., sorted in ascending order).

    // ✅ Time Complexity: O(n)
    // ✅ Space Complexity: O(1)

    void nextPermutation(vector<int>& A) {
        // Step 1: Find the pivot (first number from the right which is smaller than its next)
        int pivot = -1, n = A.size();

        for(int i = n - 2; i >= 0; i--) {
            if(A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If pivot == -1, the array is in descending order -> last permutation
        // So reverse the whole array to get the first permutation
        if(pivot == -1) {
            reverse(A.begin(), A.end());  // in-place changes
            return;
        }

        // Step 2: Find the next larger element than pivot from the right
        for(int i = n - 1; i > pivot; i--) {
            if(A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 3: Reverse the suffix (pivot+1 to end) to get the next permutation
        int i = pivot + 1, j = n - 1;
        while(i <= j) {
            swap(A[i++], A[j--]);
        }
    }
};





// ✅ Approach Summary (Commented):
// Step 1: Traverse from the end to find the first decreasing element (pivot).

// Step 2: Again from the end, find the smallest element greater than pivot and swap.

// Step 3: Reverse the suffix starting right after the pivot to make it the next permutation.




// 🔁 Dry Run (Example: A = [1, 2, 3]):
// Step 1: Pivot is at index 1 (2) because 2 < 3.

// Step 2: Swap with next greater => swap 2 and 3 → [1, 3, 2]

// Step 3: Reverse suffix after pivot → [1, 3, 2] (already correct)


#include <iostream>
#include <vector>
using namespace std;

// ? Problem: Peak Index in a Mountain Array
// A mountain array is an array where elements first strictly increase then strictly decrease.
// You have to return the index of the peak element (maximum element) in the array.

// ! Approach:
// Use Binary Search.
// At each iteration, check if the mid element is the peak.
// If A[mid-1] < A[mid] > A[mid+1], it is the peak → return mid.
// If the slope is increasing (A[mid-1] < A[mid]), move right (st = mid + 1).
// Else, move left (end = mid - 1).

// * Dry Run:
// A = [1, 3, 5, 7, 6, 4, 2]
// Iteration 1: st = 0, end = 6, mid = 3 → A[3] = 7
// A[2]=5 < A[3]=7 > A[4]=6 → peak found → return 3

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int st = 0, end = A.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
                return mid;
            } else if (A[mid - 1] < A[mid]) { // right
                st = mid + 1;
            } else { // left
                end = mid - 1;
            }
        }

        return -1;
    }
};

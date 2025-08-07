#include <iostream>
#include <vector>
using namespace std;

// ? Problem: Search in Rotated Sorted Array
// Given a sorted and rotated array A of unique integers and a target value `tar`, 
// return the index if the target is found. If not, return -1.

// ! Approach:
// Use Binary Search logic with slight modification to handle rotated sorted arrays.
// At every iteration, determine whether the left half is sorted or the right half.
// Then, check if the target lies in the sorted half and adjust the search range accordingly.

// * Dry Run:
// A = [4,5,6,7,0,1,2], tar = 0
// Iteration 1: st = 0, end = 6, mid = 3 → A[3] = 7
// Left is sorted (A[0] = 4 <= A[3] = 7), but tar = 0 not in [4,7]
// So move to right half: st = mid+1 = 4
// Iteration 2: st = 4, end = 6, mid = 5 → A[5] = 1
// Left is sorted (A[4] = 0 <= A[5] = 1), and tar = 0 in [0,1]
// So move to left half: end = mid-1 = 4
// Iteration 3: st = 4, end = 4, mid = 4 → A[4] = 0 == tar → return 4

int search(vector<int>& A, int tar) {
    int st = 0, end = A.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (A[mid] == tar) {
            return mid;
        }

        // Left half is sorted
        if (A[st] <= A[mid]) {
            if (A[st] <= tar && tar <= A[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        } 
        // Right half is sorted
        else {
            if (A[mid] <= tar && tar <= A[end]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

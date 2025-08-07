#include <iostream>
#include <vector>
using namespace std;

// ? Problem: Single Element in a Sorted Array
// You are given a sorted array where every element appears twice except one element which appears only once.
// Find that single element in O(log n) time and O(1) space.

// ! Approach:
// - Binary search approach with pairing logic.
// - Every pair will start at an even index and repeat at the next index (i.e., even-odd pairing).
// - If mid is even and A[mid] == A[mid+1], then the single element is to the right.
// - If mid is odd and A[mid] == A[mid-1], then the single element is to the right.
// - Otherwise, it’s on the left.

// * Dry Run:
// A = [1,1,2,2,3,4,4,5,5]
// st=0, end=8
// mid=4 → A[4]=3, A[3]=2, A[5]=4 → single element found → return 3

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        if (n == 1) return A[0];

        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Boundary cases
            if (mid == 0 && A[0] != A[1]) return A[mid];
            if (mid == n - 1 && A[n - 1] != A[n - 2]) return A[mid];

            // Found unique
            if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1]) return A[mid];

            if (mid % 2 == 0) { // even
                if (A[mid - 1] == A[mid]) { // pair is on left
                    end = mid - 1;
                } else { // pair is on right
                    st = mid + 1;
                }
            } else { // odd
                if (A[mid - 1] == A[mid]) { // pair is on right
                    st = mid + 1;
                } else { // pair is on left
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

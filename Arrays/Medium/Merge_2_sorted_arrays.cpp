#include <iostream>
#include <vector>
using namespace std;

/*
    ❓ Question:
    Given two sorted arrays A and B, merge B into A such that the resulting array is sorted.
    Assume A has enough space (size of A is m + n) to hold additional elements from B.

    📌 Example:
    Input: A = [1, 3, 5, 0, 0, 0], m = 3
           B = [2, 4, 6], n = 3
    Output: A = [1, 2, 3, 4, 5, 6]

    ✅ Approach:
    - Use three pointers: i = m-1 (last valid element in A), j = n-1 (last element in B), and idx = m+n-1 (last position in A).
    - Start from the end and compare A[i] and B[j]:
        - If A[i] > B[j], place A[i] at idx.
        - Else, place B[j] at idx.
        - Decrement the corresponding pointer.
    - If B has leftover elements, copy them to A.

    🔁 Dry Run:
    A = [1, 3, 5, 0, 0, 0], B = [2, 4, 6]
    i = 2, j = 2, idx = 5

    Step 1: A[i]=5 < B[j]=6 → A[5]=6
    Step 2: A[i]=5 > B[j]=4 → A[4]=5
    Step 3: A[i]=3 < B[j]=4 → A[3]=4
    Step 4: A[i]=3 > B[j]=2 → A[2]=3
    Step 5: A[i]=1 < B[j]=2 → A[1]=2
    Step 6: A[i]=1 → A[0]=1

    Final A = [1, 2, 3, 4, 5, 6]

    ⏱️ Time Complexity: O(m + n)
    🧠 Space Complexity: O(1) → In-place
*/

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) { // O(1) SC
        int idx = m + n - 1;
        int i = m - 1, j = n - 1;

        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) {
                A[idx--] = A[i--];
            } else {
                A[idx--] = B[j--];
            }
        }

        while (j >= 0) {
            A[idx--] = B[j--];
        }
    }
};

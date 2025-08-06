/*
🔷 Problem: Maximum Subarray Sum (Kadane's Algorithm)

Given an integer array `arr[]` of size `n`, find the contiguous subarray 
(with at least one number) which has the largest sum and return its sum.

🧠 Example:
Input: arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}
Output: 6
Explanation: [4, -1, 2, 1] has the largest sum = 6

--------------------------------------------

💡 Kadane's Algorithm Intuition:

1. Start from index 0 and maintain:
   - `max_current` → max subarray sum ending at current index
   - `max_global` → overall max subarray sum found so far

2. For every element:
   - max_current = max(current element, current element + max_current)
   - max_global = max(max_global, max_current)

3. The idea is: 
   - if current sum becomes negative, we reset it at next index

📌 Time Complexity: O(n)
📌 Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kadane(vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        // Check whether to start a new subarray at i or extend previous
        max_current = max(arr[i], arr[i] + max_current);
        // Update global maximum
        max_global = max(max_global, max_current);
    }

    return max_global;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int max_sum = kadane(arr);
    cout << "Maximum Subarray Sum is: " << max_sum << endl;

    return 0;
}




// # DRY RUN -----------

// Zaroor bhai, Kadane’s Algorithm ka dry run karte hain input:
// arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}

// Initialization:
// max_current = arr[0] = -2

// max_global = arr[0] = -2

// Loop starts from i = 1 to n-1
// 🔁 i = 1, arr[1] = 1
// ini
// Copy
// Edit
// max_current = max(1, 1 + (-2)) = max(1, -1) = 1
// max_global = max(-2, 1) = 1

// 🔁 i = 2, arr[2] = -3
// ini
// Copy
// Edit
// max_current = max(-3, -3 + 1) = max(-3, -2) = -2
// max_global = max(1, -2) = 1

// 🔁 i = 3, arr[3] = 4
// ini
// Copy
// Edit
// max_current = max(4, 4 + (-2)) = max(4, 2) = 4
// max_global = max(1, 4) = 4

// 🔁 i = 4, arr[4] = -1
// ini
// Copy
// Edit
// max_current = max(-1, -1 + 4) = max(-1, 3) = 3
// max_global = max(4, 3) = 4

// 🔁 i = 5, arr[5] = 2
// ini
// Copy
// Edit
// max_current = max(2, 2 + 3) = max(2, 5) = 5
// max_global = max(4, 5) = 5

// 🔁 i = 6, arr[6] = 1
// ini
// Copy
// Edit
// max_current = max(1, 1 + 5) = max(1, 6) = 6
// max_global = max(5, 6) = 6
// ✅ Yeh hai maximum subarray sum ab tak: 6

// 🔁 i = 7, arr[7] = -5
// ini
// Copy
// Edit
// max_current = max(-5, -5 + 6) = max(-5, 1) = 1
// max_global = max(6, 1) = 6

// 🔁 i = 8, arr[8] = 4
// ini
// Copy
// Edit
// max_current = max(4, 4 + 1) = max(4, 5) = 5
// max_global = max(6, 5) = 6

// ✅ Final Answer:
// ini
// Copy
// Edit
// max_global = 6
// 🧾 Subarray: [4, -1, 2, 1]

/*
🧩 Problem: Painter’s Partition Problem

Given `n` boards of different lengths represented in an array `arr[]`, and `m` painters,
allocate boards such that each painter paints **contiguous** boards and the **maximum time taken by any painter is minimized**.

Each unit length takes 1 unit time to paint.

🧠 Approach:

1. Use Binary Search on the answer — the possible range of maximum time lies between:
   - max(arr[i]) (when only 1 painter paints the largest board)
   - sum(arr[i]) (when 1 painter paints all boards)

2. For a `mid` value, use a greedy check (`isPossible()`) to see if it can be painted with `m` painters
   within `mid` time.

3. If possible → try to minimize (move left), else → move right.

Time Complexity: O(n * log(sum - max))
*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 🔍 Greedy function to check if it’s possible to paint with maxAllowedTime using ≤ m painters
bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime) { // O(n)
    int painters = 1, time = 0;

    for(int i = 0; i < n; i++) {
        if(time + arr[i] <= maxAllowedTime) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
        }
    }

    return painters <= m;
}


// 🔢 Main function to return the minimum time to paint all boards
int minTimeToPaint(vector<int> &arr, int n, int m) {
    int sum = 0, maxVal = INT_MIN;

    // 🔁 O(n): Get total sum and max board length
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal, end = sum, ans = -1;

    // 🔁 Binary search on the answer
    while(st <= end) { // O(log(sum - maxVal)) * O(n)
        int mid = st + (end - st) / 2;

        if(isPossible(arr, n, m, mid)) {
            // ✅ If possible, try for smaller time (left half)
            ans = mid;
            end = mid - 1;
        } else {
            // ❌ Not possible, go right
            st = mid + 1;
        }
    }

    return ans;
}


/*
🧪 Dry Run Example:

arr = [5, 10, 30, 20], n = 4, m = 2

sum = 65, maxVal = 30

Binary Search range = [30, 65]

Try mid = 47:
    Painter 1 → [5, 10, 30] = 45 ✅
    Painter 2 → [20] = 20 ✅ → OK

Try smaller...

Keep doing binary search until minimum possible max time is found.
*/


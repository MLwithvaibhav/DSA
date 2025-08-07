/*
🧩 Problem: Aggressive Cows

You are given an array `arr[]` of size `N` where each element represents the position of a stall.
You need to place `C` cows in these stalls such that the **minimum distance between any two cows is maximized**.

Cows can only be placed in **distinct stalls**, and **only one cow per stall**.

🧠 Approach:

1. Sort the stall positions.
2. Use Binary Search to find the maximum possible minimum distance between any two cows.
   The range of minimum distance is [1, max possible distance between stalls].
3. For a mid value, check if it's possible to place all cows such that the minimum distance between any two is at least `mid`.
   - If yes, try for larger distance (go right).
   - If not, go left.

Greedy check is done in `isPossible()` function.

⏱ Time Complexity:
- O(N log N) for sorting
- O(log(range) * N) for binary search + greedy checking
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 🔍 Greedy Function to check if we can place C cows with at least minAllowedDist distance
bool isPossible(vector<int>& arr, int N, int C, int minAllowedDist) {
    int cows = 1; // Place first cow in first stall
    int lastStallPos = arr[0];

    for(int i = 1; i < N; i++) {
        if(arr[i] - lastStallPos >= minAllowedDist) {
            cows++;
            lastStallPos = arr[i];
        }
        if(cows == C) {
            return true; // Placed all cows
        }
    }

    return false; // Not enough distance
}


// 🔢 Main Function to return the maximum minimum distance
int getDistance(vector<int>& arr, int N, int C) {
    sort(arr.begin(), arr.end()); // O(N log N)

    int st = 1; // minimum distance
    int end = arr[N - 1] - arr[0]; // maximum distance
    int ans = -1;

    // Binary Search on answer
    while(st <= end) { // O(log(range) * N)
        int mid = st + (end - st) / 2;

        if(isPossible(arr, N, C, mid)) {
            // ✅ Can place cows with at least `mid` distance, try larger
            ans = mid;
            st = mid + 1;
        } else {
            // ❌ Try smaller distance
            end = mid - 1;
        }
    }

    return ans;
}


/*
🧪 Dry Run Example:

arr = [1, 2, 4, 8, 9], N = 5, C = 3

Sort: [1, 2, 4, 8, 9]
Possible distance range = [1, 8]

Try mid = 4:
    Place 1st cow at 1
    Next possible: 4 (skip 2), place at 4
    Next: 8 (4 distance), place at 8 → ✅

Try higher distance...

Final answer = 3 (maximized minimum distance)
*/


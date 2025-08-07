#include <iostream>
#include <vector>
using namespace std;

/*
    ❓ Question:
    Given an array consisting only of 0s, 1s, and 2s, sort it in-place without using any extra space.
    This is known as the Dutch National Flag problem.

    ✅ Approach (3-pointer method):
    - Use three pointers: low, mid, and high.
    - Iterate while mid <= high:
        - If nums[mid] == 0: swap with low, move both mid and low forward.
        - If nums[mid] == 1: move mid forward.
        - If nums[mid] == 2: swap with high, move high backward.

    🔁 Dry Run (Input: [2, 0, 2, 1, 1, 0]):
    Initial: low=0, mid=0, high=5
    Step 1: nums[mid]=2 → swap(nums[0], nums[5]) → [0, 0, 2, 1, 1, 2], high--
    Step 2: nums[mid]=0 → swap(nums[0], nums[0]) → [0, 0, 2, 1, 1, 2], low++, mid++
    Step 3: nums[mid]=0 → swap(nums[1], nums[1]) → [0, 0, 2, 1, 1, 2], low++, mid++
    Step 4: nums[mid]=2 → swap(nums[2], nums[4]) → [0, 0, 1, 1, 2, 2], high--
    Step 5: nums[mid]=1 → mid++
    Step 6: nums[mid]=1 → mid++
    Loop ends → Sorted: [0, 0, 1, 1, 2, 2]

    ⏱️ Time Complexity: O(n)
    🧠 Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) { // O(n)
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                mid++; low++;
            } 
            else if (nums[mid] == 1) {
                mid++;
            } 
            else { // nums[mid] == 2
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};

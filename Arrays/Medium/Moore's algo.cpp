// ✅ Approach: **Boyer-Moore Voting Algorithm**
// - We're trying to find the majority element (appears more than n/2 times).
// - This algorithm maintains a count (freq) and a candidate (ans).
// - If freq becomes 0, we pick a new candidate.
// - If the current element is equal to the candidate, we increase freq.
// - Otherwise, we decrease freq.
// - At the end, ans contains the majority element.

#include <iostream>
#include <vector>
using namespace std;

    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                ans = nums[i];
            }

            if (ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }

            // 🔍 Dry Run Example: nums = [2,2,1,1,1,2,2]
            // i = 0, nums[i] = 2 → freq = 0 → ans = 2, freq++
            // i = 1, nums[i] = 2 → ans == nums[i] → freq++
            // i = 2, nums[i] = 1 → ans != nums[i] → freq--
            // i = 3, nums[i] = 1 → ans != nums[i] → freq--
            // i = 4, nums[i] = 1 → freq = 0 → ans = 1, freq++
            // i = 5, nums[i] = 2 → ans != nums[i] → freq--
            // i = 6, nums[i] = 2 → freq = 0 → ans = 2, freq++
            // Final ans = 2 (Majority element)
        }

        return ans;
    }


#include <iostream>
#include <vector>
using namespace std;

/*
🔷 Problem: Find two numbers in a sorted array whose sum is equal to the target.

Input:
nums = [2, 7, 11, 15], target = 13

Output:
Indices of the two numbers = [0, 2]
(2 + 11 = 13)

--------------------------------------------

💡 Approach: Two Pointer Technique (Only works on sorted arrays)

1. Keep two pointers:
   - `i` at the start (0)
   - `j` at the end (n-1)

2. While i < j:
   - If nums[i] + nums[j] == target → return {i, j}
   - If sum > target → move j--
   - If sum < target → move i++

📌 Time Complexity: O(n)
📌 Space Complexity: O(1)
*/

vector<int> pairSum(vector<int> nums, int target) {
    vector<int> ans;
    int n = nums.size();

    int i = 0, j = n - 1;

    while (i < j) {
        int pairSum = nums[i] + nums[j];

        if (pairSum > target) {
            j--;
        } else if (pairSum < target) {
            i++;
        } else {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }

    return ans; // empty if no pair found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;

    vector<int> result = pairSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No valid pair found!" << endl;
    }

    return 0;
}


/*
📄 Dry Run:

Input: nums = [2, 7, 11, 15], target = 13
i = 0, j = 3 → nums[0] + nums[3] = 2 + 15 = 17 → too big → j--
i = 0, j = 2 → 2 + 11 = 13 → match! → return [0, 2]

Output:
Indices: 0, 2
*/

#include <iostream>
#include <vector>
#include <algorithm> // for min and max
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0; // stores the maximum water area found
        int lp = 0, rp = height.size() - 1; // left and right pointers

        // Dry Run Example:
        // height = [1,8,6,2,5,4,8,3,7]
        // lp = 0, rp = 8
        // height[lp] = 1, height[rp] = 7
        // width = 8, height = min(1,7) = 1 --> area = 8
        // maxWater = 8
        // Move lp++ (since height[lp] < height[rp]) → lp = 1
        //
        // height[lp] = 8, height[rp] = 7
        // width = 7, height = 7 --> area = 49
        // maxWater = 49
        // Move rp-- (since height[lp] > height[rp]) → rp = 7
        //
        // Continue similarly...

        while (lp < rp) {
            int w = rp - lp; // width between the two lines
            int ht = min(height[lp], height[rp]); // height is minimum of the two
            int currWater = w * ht; // current water area
            maxWater = max(maxWater, currWater); // update maxWater if current is larger

            // Move the pointer pointing to the shorter line inward
            if (height[lp] < height[rp])
                lp++;
            else
                rp--;
        }

        return maxWater;
    }
};

int main() {
    Solution obj;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = obj.maxArea(height);
    cout << "Maximum water that can be contained: " << result << endl;
    return 0;
}


// Maximum water that can be contained: 49

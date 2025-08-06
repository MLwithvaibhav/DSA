#include <iostream>
#include <vector>
#include <algorithm> // for max() and min() functions

using namespace std;

/*
    Approach:
    - We want to buy at the lowest price and sell at the highest price after the buying day.
    - We traverse the prices array while tracking:
        1. `bestBuy`: The minimum price seen so far.
        2. `maxProfit`: The maximum profit if we sell on the current day.
    - For every price[i], if it is higher than bestBuy, we calculate the profit and update maxProfit.
    - If the current price is lower than bestBuy, we update bestBuy.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, bestBuy = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }

        return maxProfit;
    }
};

/*
    Dry Run Example:
    Input: prices = [7, 1, 5, 3, 6, 4]

    Step 1:
    bestBuy = 7
    i = 1 -> prices[1] = 1 < bestBuy -> bestBuy = 1
    i = 2 -> prices[2] = 5 > bestBuy -> profit = 4, maxProfit = 4
    i = 3 -> prices[3] = 3 > bestBuy -> profit = 2, maxProfit = 4
    i = 4 -> prices[4] = 6 > bestBuy -> profit = 5, maxProfit = 5
    i = 5 -> prices[5] = 4 > bestBuy -> profit = 3, maxProfit = 5

    Final maxProfit = 5
*/

int main() {
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << obj.maxProfit(prices) << endl;
    return 0;
}

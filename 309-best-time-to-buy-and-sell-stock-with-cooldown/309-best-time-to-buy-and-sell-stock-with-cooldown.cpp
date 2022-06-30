
// Tabulation + Space optimization
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> prev2(2, 0);
        vector<int> prev1(2, 0);
        vector<int> curr(2, 0);

        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                if (index == n) {  // base case
                    prev1[isEarlierBought] = 0;
                    prev2[isEarlierBought] = 0;
                } else {
                    if (isEarlierBought) {
                        // we can only sell
                        int willSell = prices[index] + prev2[false];
                        int willNotSell = 0 + prev1[true];
                        curr[isEarlierBought] = max(willSell, willNotSell);
                    } else {
                        // we can only buy
                        int willBuy = -prices[index] + prev1[true];
                        int willNotBuy = 0 + prev1[false];
                        curr[isEarlierBought] = max(willBuy, willNotBuy);
                    }
                }
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[false];
    }
};
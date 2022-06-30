
// Tabulation
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                if (index >= n) {  // base case
                    dp[index][isEarlierBought] = 0;
                } else {
                    if (isEarlierBought) {
                        // we can only sell
                        int willSell = prices[index] + dp[index + 2][false];
                        int willNotSell = 0 + dp[index + 1][true];
                        dp[index][isEarlierBought] = max(willSell, willNotSell);
                    } else {
                        // we can only buy
                        int willBuy = -prices[index] + dp[index + 1][true];
                        int willNotBuy = 0 + dp[index + 1][false];
                        dp[index][isEarlierBought] = max(willBuy, willNotBuy);
                    }
                }
            }
        }
        return dp[0][false];
    }
};

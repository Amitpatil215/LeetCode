//  Recursion + Memoization
class Solution {
   public:
    int mp(int index, bool isEarlierBought,int cap, vector<int>& prices, int n,
           vector<vector<vector<int>>>& dp) {
        if (index == n) {
            return 0;
        }
        
        if(cap==0){
            return 0;
        }

        if (dp[index][isEarlierBought][cap] != -1) {
            return dp[index][isEarlierBought][cap];
        }

        if (isEarlierBought) {
            // we can only sell
            int willSell = prices[index] + mp(index + 1, false,cap-1, prices, n, dp);
            int willNotSell = 0 + mp(index + 1, true, cap, prices, n, dp);
            return dp[index][isEarlierBought][cap] = max(willSell, willNotSell);
        } else {
            // we can only buy
            int willBuy = -prices[index] + mp(index + 1, true, cap, prices, n, dp);
            int willNotBuy = 0 + mp(index + 1, false, cap, prices, n, dp);
            return dp[index][isEarlierBought][cap] = max(willBuy, willNotBuy);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return mp(0, false, 2, prices, n, dp);
    }
};

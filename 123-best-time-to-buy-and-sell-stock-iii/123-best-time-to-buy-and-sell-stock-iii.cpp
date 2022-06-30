// Tabulation
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        
        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2; isEarlierBought++) {
                for(int cap=0; cap<=2; cap++){
                    if (index == n) {  // base case
                        dp[index][isEarlierBought][cap] = 0;
                    }else if(cap == 0){
                        dp[index][isEarlierBought][cap] = 0;
                    } else {
                        if (isEarlierBought) {
                            // we can only sell
                            int willSell = prices[index] + dp[index + 1][false][cap-1];
                            int willNotSell = 0 + dp[index + 1][true][cap];
                            dp[index][isEarlierBought][cap] = max(willSell, willNotSell);
                        } else {
                            // we can only buy
                            int willBuy = -prices[index] + dp[index + 1][true][cap];
                            int willNotBuy = 0 + dp[index + 1][false][cap];
                            dp[index][isEarlierBought][cap] = max(willBuy, willNotBuy);
                        }
                    }
                }
            }
        }
        return dp[0][false][2];
    }
};
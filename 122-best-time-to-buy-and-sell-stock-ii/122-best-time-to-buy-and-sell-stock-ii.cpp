class Solution {
public:
    int mp(int index, bool isEarlierBought,vector<int>& prices, int n,vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        
        if(dp[index][isEarlierBought]!=-1){
            return dp[index][isEarlierBought];
        }
        
        if(isEarlierBought){
            //we can only sell
            int willSell= prices[index] + mp(index+1, false, prices, n,dp);
            int willNotSell= 0 + mp(index+1, true, prices, n,dp);
            return dp[index][isEarlierBought] = max(willSell, willNotSell);
        }else{
            // we can only buy
            int willBuy = -prices[index] + mp(index+1, true, prices, n, dp);
            int willNotBuy = 0 + mp(index+1, false, prices, n,dp);
            return dp[index][isEarlierBought] = max(willBuy, willNotBuy);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int index=n;index>=0;index--){
            for(int isEarlierBought=0;isEarlierBought<2;isEarlierBought++){
                
                if(index==n){ //base case
                    dp[index][isEarlierBought] = 0;
                }else{
                    if(isEarlierBought){
                        //we can only sell
                        int willSell= prices[index] + dp[index+1][false];
                        int willNotSell= 0 + dp[index+1][true];
                        dp[index][isEarlierBought] = max(willSell, willNotSell);
                    }else{
                        // we can only buy
                        int willBuy = -prices[index] + dp[index+1][true];
                        int willNotBuy = 0 + dp[index+1][false];
                        dp[index][isEarlierBought] = max(willBuy, willNotBuy);
                    }    
                }
            }  
        }
        return dp[0][false];
    }
};
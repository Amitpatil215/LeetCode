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
        
        vector<int> prev(2,0);
        vector<int> curr(2,0);
        
        for(int index=n;index>=0;index--){
            for(int isEarlierBought=0;isEarlierBought<2;isEarlierBought++){
                
                if(index==n){ //base case
                    prev[isEarlierBought] = 0;
                }else{
                    if(isEarlierBought){
                        //we can only sell
                        int willSell= prices[index] + prev[false];
                        int willNotSell= 0 + prev[true];
                        curr[isEarlierBought] = max(willSell, willNotSell);
                    }else{
                        // we can only buy
                        int willBuy = -prices[index] + prev[true];
                        int willNotBuy = 0 + prev[false];
                        curr[isEarlierBought] = max(willBuy, willNotBuy);
                    }    
                }
            }
            prev = curr;
        }
        return prev[false];
    }
};
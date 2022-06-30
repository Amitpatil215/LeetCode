class Solution {
public:
    int mp(int index, int isEarlierBought, vector<int>& prices, int fee, int n, vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        if(dp[index][isEarlierBought]!=-1){
            return dp[index][isEarlierBought];
        }
        
        if(isEarlierBought){
            // we can only sell
            int willSell = prices[index] - fee + mp(index+1,false,prices,fee,n ,dp);
            int willNotSell = 0 + mp(index+1,true,prices,fee,n ,dp);
            return dp[index][isEarlierBought] = max(willSell,willNotSell);
        }else{
            // we can only buy
            int willBuy = - prices[index] + mp(index+1,true,prices,fee,n,dp);
            int willNotBuy = 0 + mp(index+1,false,prices,fee,n ,dp);
            return dp[index][isEarlierBought] = max(willBuy,willNotBuy);
        }
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        vector<int> prev(2,false);
        vector<int> curr(2,false);
        for(int index=n; index>=0; index--){
            for(int isEarlierBought=0; isEarlierBought<2; isEarlierBought++){
                if(index==n){
                    prev[isEarlierBought] =0;
                }else{
                    if(isEarlierBought){
                        // we can only sell
                        int willSell = prices[index] - fee + prev[false]; 
                        int willNotSell = 0 + prev[true];
                        curr[isEarlierBought] = max(willSell,willNotSell);
                    }else{
                        // we can only buy
                        int willBuy = - prices[index] + prev[true];
                        int willNotBuy = 0 + prev[false];
                        curr[isEarlierBought] = max(willBuy,willNotBuy);
                    }
                }
            }
            prev = curr;
        }
        return prev[false];
    }
};
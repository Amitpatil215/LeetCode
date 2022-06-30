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
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return mp(0,false,prices,fee,n,dp);
    }
};
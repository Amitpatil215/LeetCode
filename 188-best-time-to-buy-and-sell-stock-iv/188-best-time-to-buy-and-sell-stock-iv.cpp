class Solution {
public:
    int mp(int index, bool isBuyingAllowed, int k, vector<int>& prices,vector<vector<vector<int>>> &dp){
        
        // base case
        if(k==0){
            return 0;
        }
        if(index == prices.size()){
            return 0;
        }

        if(dp[index][isBuyingAllowed][k]!=-1){
            return dp[index][isBuyingAllowed][k];
        }
        // recursive case
        if(isBuyingAllowed){
            int buy = - prices[index] + mp(index+1, false, k, prices,dp); 
            int doNotbuy= mp(index+1, true, k, prices,dp);
            return dp[index][isBuyingAllowed][k] = max(buy, doNotbuy); 
        }else{
            int sell = prices[index] + mp(index+1, true, k-1, prices,dp);
            int doNotSell = mp(index+1, false, k, prices,dp);
            return dp[index][isBuyingAllowed][k] = max(sell , doNotSell); 
        }
    }
    int maxProfit(int K, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(K+1,0)));
        // return mp(0, true, K, prices,dp);
        for(int index=prices.size(); index>=0;index--){
            for(int isBuyingAllowed = 0; isBuyingAllowed<=1; isBuyingAllowed++){
                for(int k=0; k<=K; k++){
                    if(index == prices.size()){
                        dp[index][isBuyingAllowed][k] = 0;
                    }else if(k==0){
                        dp[index][isBuyingAllowed][k] = 0;
                    }else{
                        if(isBuyingAllowed){
                            int buy = - prices[index] + dp[index+1][false][k];
                            int doNotbuy=dp[index+1][true][k];
                            dp[index][isBuyingAllowed][k] = max(buy, doNotbuy); 
                        }else{
                            int sell = prices[index] + dp[index+1][true][k-1];
                            int doNotSell = dp[index+1][false][k];
                            dp[index][isBuyingAllowed][k] = max(sell , doNotSell); 
                        }
                    }
                }
            }
        }
        return dp[0][true][K];
    }
};
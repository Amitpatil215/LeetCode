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
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return mp(0, true, k, prices,dp);
    }
};
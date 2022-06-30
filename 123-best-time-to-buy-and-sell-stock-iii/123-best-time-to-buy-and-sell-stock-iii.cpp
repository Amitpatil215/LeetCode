// Tabulation
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(3,0));
        vector<vector<int>> curr(2, vector<int>(3,0));
        
        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2; isEarlierBought++) {
                for(int cap=0; cap<=2; cap++){
                    if (index == n) {  // base case
                        prev[isEarlierBought][cap] = 0;
                    }else if(cap == 0){
                        curr[isEarlierBought][cap] = 0;
                    } else {
                        if (isEarlierBought) {
                            // we can only sell
                            int willSell = prices[index] + prev[false][cap-1];
                            int willNotSell = 0 + prev[true][cap];
                            curr[isEarlierBought][cap] = max(willSell, willNotSell);
                        } else {
                            // we can only buy
                            int willBuy = -prices[index] + prev[true][cap];
                            int willNotBuy = 0 + prev[false][cap];
                            curr[isEarlierBought][cap] = max(willBuy, willNotBuy);
                        }
                    }
                }
            }
            prev = curr;
        }
        return prev[false][2];
    }
};
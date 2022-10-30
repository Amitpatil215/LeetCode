class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int minPriceSoFar=INT_MAX;
        int maxProfitSoFar=0;
        for(int i=0;i<n;i++){
            minPriceSoFar=min(minPriceSoFar, prices[i]);
            maxProfitSoFar=max(maxProfitSoFar,prices[i]-minPriceSoFar);
        }
        return maxProfitSoFar;
    }
};
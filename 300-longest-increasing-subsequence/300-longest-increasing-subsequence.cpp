class Solution {
public:
    int lOLIS(int index, int earlierIndex, vector<int>&nums, int &n, vector<vector<int>>&dp){
        if(index == n){
            return 0;
        }
        if(dp[index][earlierIndex+1]!=-1){
            return dp[index][earlierIndex+1];
        }
        
        if(earlierIndex == -1 || nums[index] > nums[earlierIndex] ){
            int take = 1 + lOLIS(index+1, index, nums, n, dp);
            int doNotTake = 0 + lOLIS(index+1, earlierIndex , nums, n, dp);
            return dp[index][earlierIndex+1] = max(take, doNotTake);
        }else{
            int doNotTake = 0 + lOLIS(index+1, earlierIndex , nums, n, dp);
            return dp[index][earlierIndex+1] = doNotTake;
        }
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return lOLIS(0,-1,nums,n,dp);    
    }
};
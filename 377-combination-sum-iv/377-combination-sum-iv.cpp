class Solution {
public:
    int cs4(vector<int>& nums, int target,vector<int> &dp){
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        
        int noOfWays=0;
        for(int i=0;i<nums.size();i++){
            noOfWays += cs4(nums,target-nums[i],dp);
        }
        return dp[target] = noOfWays;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return cs4(nums,target,dp);
    }
};
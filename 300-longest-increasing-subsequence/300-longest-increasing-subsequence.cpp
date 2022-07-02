class Solution {
   public:
    int lOLIS(int index, int earlierIndex, vector<int>& nums, int& n,
              vector<vector<int>>& dp) {
        if (index == n) {
            return 0;
        }
        if (dp[index][earlierIndex + 1] != -1) {
            return dp[index][earlierIndex + 1];
        }

        if (earlierIndex == -1 || nums[index] > nums[earlierIndex]) {
            int take = 1 + lOLIS(index + 1, index, nums, n, dp);
            int doNotTake = 0 + lOLIS(index + 1, earlierIndex, nums, n, dp);
            return dp[index][earlierIndex + 1] = max(take, doNotTake);
        } else {
            int doNotTake = 0 + lOLIS(index + 1, earlierIndex, nums, n, dp);
            return dp[index][earlierIndex + 1] = doNotTake;
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        
        int maxLength=1;
        for(int index=0; index<n;index++){
            for(int earlierIndex =0; earlierIndex<=index-1;earlierIndex++){
                if(nums[earlierIndex] < nums[index]){
                    dp[index] = max(dp[index], 1 + dp[earlierIndex]);
                }
            }
            maxLength =max(maxLength, dp[index]);
        }
        return maxLength;
        
    }
};

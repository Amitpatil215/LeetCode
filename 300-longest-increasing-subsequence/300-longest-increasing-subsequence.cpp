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

        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        
        for(int index = n ; index>=0; index--){
            // earlier index will definitely be lying from -1 to index-1 so
            for(int earlierIndex= index-1 ; earlierIndex>=-1; earlierIndex--){
                if (index == n) {
                    prev[earlierIndex+1] = 0;
                }else{
                        if (earlierIndex == -1 || nums[index] > nums[earlierIndex]) {
                        int take = 1 + prev[index+1];
                        int doNotTake = 0 + prev[earlierIndex+1];
                        curr[earlierIndex + 1] = max(take, doNotTake);
                    } else {
                        int doNotTake = 0 + prev[earlierIndex+1];
                        curr[earlierIndex + 1] = doNotTake;
                    }
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};

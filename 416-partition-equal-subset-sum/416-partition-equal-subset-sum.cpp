class Solution {
public:
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // one noteable change here we are creating boo vector of target+1 size instead of (target/2 +1)
    // which is our k 
    // it will get out of boud in the second else if dp[0][arr[0]] as there may not be any array[0]
    // in within (e.g array is {100})
    
    vector<vector<bool>> dp(n+1, vector<bool>(2*k +1, false));
    for (int i = 0; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            // if target is zero then must be true
            if (target == 0) {
                dp[i][0] = true;
            } else if (i == 0) {
                dp[0][arr[0]] = true;
            } else {
                bool take = false;
                bool doNotTake = false;
                if (i > 0 && target - arr[i] >= 0)
                    take = dp[i - 1][target - arr[i]];
                if (i > 0) doNotTake = dp[i - 1][target];
                dp[i][target] = take | doNotTake;
            }
        }
    }
    return dp[n - 1][k];
}

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2==0){
            return subsetSumToK(nums.size(),sum/2,nums);
        }else{
            return false;
        }
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=0;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxSum = max(maxSum,sum);
            if(sum<0){
                sum=0;
            }
        }
        int mini =*max_element(nums.begin(),nums.end());
        if(maxSum!=0 || (maxSum==0 && mini==0))
            return maxSum;
        return mini;
        
        
    }
};
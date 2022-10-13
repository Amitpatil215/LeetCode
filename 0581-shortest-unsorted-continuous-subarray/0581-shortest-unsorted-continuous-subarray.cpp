class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int end=-1;
        int leftMax = nums[0];
        for(int i=1;i<nums.size();i++){
            if(leftMax>nums[i]){
                end=i;
            }else{
                leftMax = nums[i];   
            }
        }
        
        //for start
        int start=0;
        int rightMin = nums[nums.size()-1];
        for(int i=nums.size()-1;i>=0;i--){
            if(rightMin<nums[i]){
                start=i;
            }else{
                rightMin = nums[i];   
            }
        }
        return end-start +1;
    }
};
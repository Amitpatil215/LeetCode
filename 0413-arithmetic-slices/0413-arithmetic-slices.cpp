class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // we should have atleat 3 elemnets in the nums
        if(nums.size()<3){
            return 0;
        }
        
        // at every ith index denotes, no of subarrays ending on that index
        vector<int>ans(nums.size(),0);
        
        // iterate over the nums and check wheter current, current-1, current-2
        // have same common difference or not i.e in Arithmetic Progression
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                // if they are in AP
                // then we can include current subaary and extend previous one to
                // end at current index
                ans[i]=ans[i-1]+1;
            }
        }
        
        //count all subarrys 
        int count=0;
        for(int i=0;i<ans.size();i++){
            count+=ans[i];
        }
        return count;
    }
};
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        
        int sum =0;
        
        //intial even value sum
        for(int i:nums){
            if(i%2==0){
                sum+=i;
            }
        }
        
        for(auto q: queries){
            int val = q[0];
            int index=q[1];
            //if alredy even then remove it from sum
            if(nums[index]%2==0){
                sum-=nums[index];
            }
            //update the array
            nums[index] +=val;
            
            if(nums[index]%2==0){
                sum+=nums[index];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
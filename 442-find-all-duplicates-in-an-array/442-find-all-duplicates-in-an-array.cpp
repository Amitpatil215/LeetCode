class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int j=nums[i]-1;
            if(nums[i]!=nums[j]){
                swap(nums[i],nums[j]);
            }else{
                i++;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]-1!=i){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
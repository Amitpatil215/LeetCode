class Solution {
public:
    vector<vector<int>>twoSum(vector<int>&nums, int target, int si){
        //asuming that nums is sorted alredy
        vector<vector<int>>ans;
        int left=si,right=nums.size()-1;
        while(left<right){
            //if duplicate found then skip  
            if(left!=si && nums[left]==nums[left-1]){
                left++;
                continue;
            }
            int sum = nums[left] +nums[right];
            if(target==sum){
                vector<int>subAns(2);
                subAns[0]=nums[left];
                subAns[1]=nums[right];

                ans.push_back(subAns);
                left++;right--;
            }else if(sum<target){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }

            vector<vector<int>>subAns=twoSum(nums,0-nums[i],i+1);

            for(auto &vec:subAns){
                vec.push_back(nums[i]);
                ans.push_back(vec);
            }
        }
        return ans;
    }
};
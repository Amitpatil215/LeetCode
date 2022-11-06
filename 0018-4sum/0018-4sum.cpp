class Solution {
public:
    vector<vector<int>>twoSum(vector<int>&nums, long target, int si){
        //asuming that nums is sorted alredy
        vector<vector<int>>ans;
        int left=si,right=nums.size()-1;
        while(left<right){
            //if duplicate found then skip  
            if(left!=si && nums[left]==nums[left-1]){
                left++;
                continue;
            }
            long sum = nums[left] +nums[right];
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
    vector<vector<int>> threeSum(vector<int>& nums, long target,int si) {
        
        vector<vector<int>>ans;
        for(int i=si;i<nums.size()-2;i++){
            if(i!=si && nums[i]==nums[i-1]){
                continue;
            }

            vector<vector<int>>subAns=twoSum(nums,target-nums[i],i+1);

            for(auto &vec:subAns){
                vec.push_back(nums[i]);
                ans.push_back(vec);
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()<4) return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-3;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }

            vector<vector<int>>subAns=threeSum(nums,target-nums[i],i+1);

            for(auto &vec:subAns){
                vec.push_back(nums[i]);
                ans.push_back(vec);
            }
        }
        return ans;
    }
};
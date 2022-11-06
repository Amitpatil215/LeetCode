class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>elements;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(elements.find(target-nums[i])!=elements.end()){
                ans.push_back(i);
                ans.push_back(elements[target-nums[i]]);
                return ans;
            }
            elements[nums[i]]=i;
        }
        return ans;
    }
        
};
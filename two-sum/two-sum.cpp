class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> myMap;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int element=target-nums[i];
            
            if(myMap.count(element)>0){
                ans.push_back(i);
                ans.push_back(myMap[element]);
                break;
            }else{
                myMap[nums[i]]=i;
            }
        }
        return ans;
    }
};
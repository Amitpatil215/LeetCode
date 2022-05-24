class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for(auto i:nums){
            int size=ans.size();
            for(int j=0;j<size;j++){
                vector<int> sub=ans[j];
                sub.push_back(i);
                ans.push_back(sub);
            }
        }
        return ans;
    }
};
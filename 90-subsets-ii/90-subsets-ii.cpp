class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back({});
        int ei=0;
        int si=0;
        for(int i=0;i<nums.size();i++ ){
            si=0;
            if(i>0 && nums[i]==nums[i-1]){
                si=ei+1;
            }
            ei=ans.size()-1;
            for(int j=si;j<=ei;j++){
                vector<int> sub=ans[j];
                sub.push_back(nums[i]);
                ans.push_back(sub);
            }
        }
        return ans;
    }
};
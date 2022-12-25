class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
       sort(nums.begin(),nums.end());
        vector<int>prefix(nums.size());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix[i]=sum;
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int q = queries[i];
            int index = lower_bound(prefix.begin(),prefix.end(),q)-prefix.begin();
            if(index!=nums.size() && prefix[index]==q){
                ans[i]=index+1;
            }else{
                ans[i]=index;
            }
        }
        return ans;
    }
};
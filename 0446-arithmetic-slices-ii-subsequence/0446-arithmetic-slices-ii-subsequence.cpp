class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        vector<unordered_map<long,int>>subSequenceCountEndingAtI(nums.size(),unordered_map<long,int>());
        int count=0;
        for(int i=1;i<nums.size();i++){
            int currElement = nums[i];
            for(int j=0;j<i;j++){
                long diff = (long)currElement - nums[j];
                if(subSequenceCountEndingAtI[j].count(diff)>0){    
                   count+=subSequenceCountEndingAtI[j][diff];
                }
                subSequenceCountEndingAtI[i][diff]+=subSequenceCountEndingAtI[j][diff] + 1;
            }
        }
        return count;
    }
};
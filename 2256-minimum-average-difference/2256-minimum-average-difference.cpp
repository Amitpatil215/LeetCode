class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long>prefix(nums.size(),0);
        vector<long>suffix(nums.size(),0);
        long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix[i]=sum;
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            suffix[i]=sum;
        }
        
        //now check for min avg diff
        int index=-1;
        long minDiff=INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            long prefixSumAvg = prefix[i] / (i+1);  
            long suffixSumAvg = (i+1) <=nums.size()-1 ? (suffix[i+1])/(nums.size()-i-1) : 0;
            long currDiff  = abs(prefixSumAvg-suffixSumAvg);
            // cout<<currDiff<<" "<<i<<endl;
            if(currDiff < minDiff){
                index = i;
                 minDiff = currDiff;
            }
        }
        return index;
    }
};
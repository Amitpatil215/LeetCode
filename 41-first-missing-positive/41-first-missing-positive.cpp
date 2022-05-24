class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long n=nums.size();
        long long i=0;
        nums.resize(n+1);
        while(i<n){
            // long long j=nums[i]-1;
            
            if(nums[i]>0 && nums[i]<=n  && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        
        cout<<endl;
        for(long long i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
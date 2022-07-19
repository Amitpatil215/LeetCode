class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // int arr[101];
        int count[101]={0};
        for(auto no:nums){
            count[no]++;
        }
        // prefix count array
        for(int i=1;i<101;i++){
            count[i]=count[i-1] +count[i];
        }
        //build ans;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int pos = nums[i];
            if(pos==0) ans.push_back(0);
            else
            ans.push_back(count[pos-1]);
        }
        return ans;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorx=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            xorx^=nums[i];
        }
        int xora=0;
        for(int i=0;i<n+1;i++){
            xora^=i;
        }
        return xorx^xora;
    }
};
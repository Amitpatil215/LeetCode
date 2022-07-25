class Solution {
public:
    int binarySearch(bool isFirst,int s, int e,int target,vector<int>& nums){
        int ans =-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                if(isFirst){
                    ans = mid;
                    e = mid -1;
                }else{
                    ans = mid;
                    s = mid + 1;
                }
            }else if(nums[mid]<target){
                s=mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        ans[0] = binarySearch(true, 0 ,nums.size()-1,target, nums);
        ans[1] = binarySearch(false, 0 ,nums.size()-1,target, nums);
        return ans;
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i1=-1, n=nums.size();
        for(int i=n-1;i>=1;i--){
            if(nums[i-1] < nums[i]){
                i1 = i-1;
                break;
            }
        }
        
        if(i1==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        int i2=-1;
        for(int i=n-1; i>i1;i--){
            if(nums[i1]<nums[i]){
                i2=i;
                break;
            }
        }
        cout<<i1<<i2<<endl;
        swap(nums[i1],nums[i2]);
        int i=i1+1, j=n-1;
        while(i<=n-1 && j>=0 && i<j){
            swap(nums[i],nums[j]);
            i++;j--;
        }
    }
};
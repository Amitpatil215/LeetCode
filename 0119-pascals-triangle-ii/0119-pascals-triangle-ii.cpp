class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        ans[0]=1;
        long curVal=1;
        for(int i=1;i<=rowIndex;i++){
            curVal  =(curVal * (rowIndex-i+1))/(i-1+1);
            ans[i] = curVal;
        }
        return ans;
    }
};
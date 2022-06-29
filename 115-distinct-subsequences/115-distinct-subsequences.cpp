class Solution {
public:
    int nd(int index1, int index2, string &str1, string &str2, vector<vector<int>> &dp){
        // we exhausted the target string
        if(index2 < 0){
            return 1;
        }
        // we exhausted original string but not target
        if(index1 <0){
            return 0;
        }
        
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        
        if(str1[index1]==str2[index2]){
            return dp[index1][index2] = nd(index1-1, index2-1,str1,str2,dp) + nd(index1-1, index2,str1,str2,dp);
        }else{
            return dp[index1][index2] = nd(index1-1,index2,str1,str2,dp);
        }
    }
    
    int numDistinct(string s, string t) {
        int l1=s.size();
        int l2=t.size();
        vector<vector<int>> dp(l1,vector<int>(l2,-1));
        return nd(l1-1,l2-1,s,t,dp);
    }
};
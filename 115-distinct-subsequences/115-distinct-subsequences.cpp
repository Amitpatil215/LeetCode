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
        string str1 = s;
        string str2 = t;
        int mod = (1e9 +7);
        vector<vector<int>> dp(l1+1 ,vector<int>(l2+1,0));
        
        // for base case
        for(int index1=0;index1<=l1; index1++){
            //we got our sbsequequence as we are follwoing 1 based indexing in this if index2==0
            dp[index1][0] = 1;    
        }
        
        for(int index1=1; index1<=l1; index1++){
            for(int index2=1; index2<=l2; index2++){
                if(str1[index1-1]==str2[index2-1]){
                    int take = dp[index1-1][index2-1];
                    int doNotTake = dp[index1-1][index2];
                    dp[index1][index2] = (take + doNotTake) % mod; 
                }else{
                    dp[index1][index2] = dp[index1-1][index2];
                }
                
            }
        }
        return dp[l1][l2];
    }
};
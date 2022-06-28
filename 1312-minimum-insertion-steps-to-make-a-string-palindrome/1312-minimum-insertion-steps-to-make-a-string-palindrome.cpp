class Solution {
public:
    int lps(string &s1, string &s2){
        int len = s1.size();
        vector<vector<int>>dp(len+1,vector<int>(len+1,0));
        
        for(int index1=1; index1<=len; index1++){
            for(int index2=1; index2<=len; index2++){
                if(s1[index1-1]==s2[index2-1]){
                    dp[index1][index2] = 1 + dp[index1-1][index2-1];  
                }else{
                    dp[index1][index2] = 0 + max(dp[index1-1][index2],dp[index1][index2-1]);
                }
            }
        }
        return dp[len][len];
    }
    
    int minInsertions(string s) {
        string str1=s;
        string str2=s;
        reverse(str2.begin(),str2.end());
        
        // find length of longest palindromic subsequence
        int len_of_lps =lps(str1,str2);
        return s.size() - len_of_lps;
    }
};
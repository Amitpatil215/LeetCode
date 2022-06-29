class Solution {
public:
    
    int md(int index1, int index2, string &word1, string &word2, vector<vector<int>> &dp){
        // base case
        if(index1 < 0){
            return index2+1;
        }
        
        if(index2 < 0){
            return index1+1;
        }
        
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        
        // recursive case
        if(word1[index1]==word2[index2]){
            // found a match
            return dp[index1][index2] = 0 + md(index1-1, index2-1, word1, word2, dp);
        }else{
            int deleteOperation = md(index1-1, index2, word1, word2,dp);
            int insertOperation = md(index1, index2-1, word1, word2,dp);
            int replaceOperation = md(index1-1, index2-1, word1, word2,dp);
            return dp[index1][index2] = 1 + min(deleteOperation, min(insertOperation,replaceOperation));
        }
    }
    int minDistance(string word1, string word2) {
        int len1= word1.size();
        int len2= word2.size();
        vector<vector<int>> dp(len1,vector<int>(len2,-1));
        return md(len1-1, len2-1, word1, word2,dp);
    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1= word1.size();
        int len2= word2.size();
        
        vector<int> prev(len2+1,0);
        vector<int> curr(len2+1,0);
        
        // base case  

        for(int index2=0;index2<=len2; index2++){
            prev[index2] = index2; // dp[0] will be our prev row as we are following 1 based indexing
        }

        // we will not rquire this anymore as we relying on only two rows prev and curr
        // so no need to assign other values like dp[2][0]=2, dp[3][0]=3...so on
        //* but we need to make sure that every curr[0]=index1 ..see for loop 
        /* for(int index1=0;index1<=len1; index1++){
            dp[index1][0] = index1;
        } */
        
        for(int index1=1; index1<=len1; index1++){
            curr[0]=index1;
            for(int index2=1; index2<=len2; index2++){
                if(word1[index1-1]==word2[index2-1]){
                    // found a match
                    curr[index2] = 0 + prev[index2-1];
                }else{
                    int deleteOperation = prev[index2];
                    int insertOperation = curr[index2-1];
                    int replaceOperation = prev[index2-1];
                    curr[index2] = 1 + min(deleteOperation, min(insertOperation,replaceOperation));
                }
            }
            prev = curr;
        }
        return prev[len2];
        
    }
};
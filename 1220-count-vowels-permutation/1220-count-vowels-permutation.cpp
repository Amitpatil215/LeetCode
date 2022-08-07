class Solution {
public:
    int mod = (1e9)+7;
    vector<char> vowels={'a', 'e', 'i', 'o', 'u'};
    int cvp(int len,int earlier,vector<vector<int>>&dp){
        if(len==0){
            return 1;
        }
        
        if(earlier >=0 && dp[len][earlier]!=-1){
            return dp[len][earlier];
        }
        if(earlier==-1){
            int ans=0;
            for(int i=0;i<5;i++){
                 ans= (ans%mod + cvp(len-1,i,dp)%mod)%mod; 
            }
            return ans;
        }else if(earlier==0){
            return dp[len][earlier] = cvp(len-1,1,dp)%mod;
        }else if(earlier==1){
            return dp[len][earlier] = ((cvp(len-1,0,dp))%mod + (cvp(len-1,2,dp)%mod))%mod;
        }else if(earlier==2){
            int ans=0;
            for(int i=0;i<5;i++){
                if(i!=2) 
                ans=((ans %mod) + (cvp(len-1,i,dp)%mod))%mod; 
            }
            return dp[len][earlier] = ans;
        }else if(earlier==3){
            return dp[len][earlier] = (cvp(len-1,2,dp)%mod + cvp(len-1,4,dp)%mod)%mod;
        }else if(earlier==4){
            return dp[len][earlier] = cvp(len-1,0,dp)%mod;
        }else{
            return 0;
        }
    }
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        return cvp(n,-1,dp)%mod;
    }
};
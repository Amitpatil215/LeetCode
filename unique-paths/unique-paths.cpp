class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans=1;
        for(int i=n;i<=n+m-2;i++){
            ans=ans*i;
            ans=ans/(i-n+1);
        }
        return ans;
    }
};
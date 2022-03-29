// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int s[], int m, int n) {
        
        long long int dp[n+1]={0};
        dp[0]=1;
        for(long long int i=0;i<m;i++){
            for(int j=s[i];j<n+1;j++){
                dp[j]+=dp[j-s[i]];
            }
        }
        return dp[n];
        // code here.
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
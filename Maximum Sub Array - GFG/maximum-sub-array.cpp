// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    vector<int> maxSubArray;//
	    int maxSubArrayStart=0;
	    int maxSubArrayEnd=0;
	    
	    long long int maxSum=0;
	    
	    int si=0;
	    vector<int> currSubArray;//
	    int currSubArrayStart=0;
	    int currSubArrayEnd = 0;
	    long long int currSum=0;
	    for(int i=0; i<n;i++){
	        if(currSubArrayStart==-1) currSubArrayStart=i;
	        if(a[i]>=0){
	           // currSubArray.push_back(a[i]);
	           currSubArrayEnd=i;
	            currSum+=a[i];
	            
	            if(currSum>maxSum || (currSum==maxSum && ((maxSubArrayEnd-maxSubArrayStart) < (currSubArrayEnd-currSubArrayStart)))){
	                maxSum = currSum;
	               // maxSubArray = currSubArray;
	               	maxSubArrayStart=currSubArrayStart;
	                maxSubArrayEnd=currSubArrayEnd;
	            }
	        }else{
	           // currSubArray.clear();
	            currSubArrayStart=-1;
	            currSum=0;
	        }
	    }
	    if(maxSum==0) return {-1};
	    vector<int> ans;
	    for(int i=maxSubArrayStart; i<=maxSubArrayEnd; i++){
	        ans.push_back(a[i]);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends
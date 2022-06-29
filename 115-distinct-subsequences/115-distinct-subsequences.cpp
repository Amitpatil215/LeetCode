class Solution {
public:
    int numDistinct(string s, string t) {
        int l1=s.size();
        int l2=t.size();
        string str1 = s;
        string str2 = t;
        int mod = (1e9 +7);
        
        vector<int> prev(l2+1, 0);
        
        // for base case
        //we got our sbsequequence as we are follwoing 1 based indexing in this if index2==0
        prev[0] = 1;
        
        for(int index1=1; index1<=l1; index1++){
            for(int index2=l2; index2>=1; index2--){
                if(str1[index1-1]==str2[index2-1]){
                    int take = prev[index2-1];
                    int doNotTake = prev[index2];
                    prev[index2] = (take + doNotTake) % mod; 
                }else{
                    prev[index2] = prev[index2];
                }
                
            }
        }
        return prev[l2];
    }
};
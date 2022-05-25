class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        ans.push_back("");
        for(char a:s){
            
            int n=ans.size();
            for(int i=0;i<n;i++){
                if(isalpha(a)){
                    string exiting=ans[i];
                    char lower=tolower(a);
                    char upper=toupper(a);
                    ans.push_back(ans[i]+upper);
                    ans[i]=ans[i]+lower;
                }else{
                    ans[i]=ans[i]+a;
                }
            }
        }
        return ans;
    }
};
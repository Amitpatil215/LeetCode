class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0},b[26]={0};
        for(auto x:s){
            a[x-'a']++;
        }
        for(auto x:t){
            b[x-'a']++;
        }
        
        for(int i=0;i <26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
};
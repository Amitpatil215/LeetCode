class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        istringstream ss(s);   
        string word="";
        bool isFirst=true;
        while(ss>>word){
            if(!isFirst) ans+=" ";
            isFirst = false;
            reverse(word.begin(),word.end());
            ans+=word;
        }
        
        return ans;
    }
};
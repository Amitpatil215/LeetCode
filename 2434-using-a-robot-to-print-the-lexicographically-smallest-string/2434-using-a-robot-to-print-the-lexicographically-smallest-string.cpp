class Solution {
public:
    char low(vector<int> &freq){
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return 'a'+ i;
        }
        return 'a';
    }
    string robotWithString(string s) {
       stack<char> st;
        vector<int> freq(26,0);
        for(auto c:s){
            freq[c-'a']++;
        }
        string ans="";
        for(auto c:s){
            freq[c-'a']--;
            st.push(c);
            while(!st.empty() && st.top()<=low(freq)){
                ans+=st.top();
                st.pop();
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
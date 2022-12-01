class Solution {
public:
    bool halvesAreAlike(string str) {
        vector<char> vec={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        set<char>s(vec.begin(),vec.end());
        int count=0;
        for(int i=0; i<str.size(); i++){
            auto c = str[i];
            if(s.find(c)!=s.end() && i<(str.size()/2)){
                count++;
            }else if(s.find(c)!=s.end()){
                count--;
            }
        }
        if(count==0) return true;
        return false;
    }
};
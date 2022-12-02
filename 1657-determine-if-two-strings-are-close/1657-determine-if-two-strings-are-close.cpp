class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<int,int>w1f,w2f;
        unordered_map<int,int>freq;
        set<char>uniqueChars;
        for(auto x:word1){
            w1f[x]++;
            uniqueChars.insert(x);
        }
        for(auto x:word2){
            w2f[x]++;
        }
        for(auto x:w1f){
            freq[x.second]++;
        }
        
        for(auto x: w2f){
            if(uniqueChars.find(x.first)!=uniqueChars.end()){
                uniqueChars.erase(x.first);
            }else{
                return false;
            }
            if(freq.find(x.second)!=freq.end()){
                freq[x.second]--;
                if(freq[x.second]==0){
                    freq.erase(x.second);
                }
            }else{
                return false;
            }
        }
        
        if(freq.size()==0 && uniqueChars.size()==0){
            return true;
        }
        return false;
    }
};
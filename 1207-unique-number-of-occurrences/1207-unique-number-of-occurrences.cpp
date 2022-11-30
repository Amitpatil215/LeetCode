class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(auto x:arr){
            freq[x]++;
        }
        unordered_set<int>check;
        for(auto x:freq){
            if(check.find(x.second)==check.end()){
                check.insert(x.second);
            }else{
                return false;
            }
        }
        return true;
    }
};
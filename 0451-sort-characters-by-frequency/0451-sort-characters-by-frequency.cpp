class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto x:s){
            freq[x]++;
        }
        
        vector<pair<int,char>>vec;
        for(auto x:freq){
            vec.push_back({x.second,x.first});
        }
        sort(vec.begin(),vec.end(),greater<>());
        string ans="";
        for(auto x:vec){
            
            for(int i=0;i<x.first;i++){
                ans+=x.second;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,pair<int,char>>freq;
        string ans;
        
        for(auto e:s){
            freq[e]={freq[e].first+1,e};
        }
        priority_queue<pair<int,char>>pq;
        for(auto m:freq){
            pq.push(m.second);
        }
        
        while(!pq.empty()){
            for(int i=0;i<pq.top().first;i++){
                ans+=pq.top().second;
            }
            pq.pop();
        }
      
        return ans;
    }
};
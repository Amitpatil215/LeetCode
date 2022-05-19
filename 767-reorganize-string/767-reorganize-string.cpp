class compare{
    public: 
    bool operator()(pair<char,int>p1,pair<char,int>p2){
        return p2.second>p1.second;
    }    
};

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        
        unordered_map<char,pair<int,char>>freq;
        
        for(auto c:s){
            freq[c]={freq[c].first+1,c};
        }
        
        for(auto m:freq){
            pq.push(m.second);
        }
        pair<int,char> prev={-1,'x'};
        
        string ans="";
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            
            if(prev.first>0){
                pq.push(prev);    
            }
            
            prev={top.first-1,top.second};
            
            ans+=top.second;
            
        }
        return ans.length()==s.length()?ans:"";
        
    }
};
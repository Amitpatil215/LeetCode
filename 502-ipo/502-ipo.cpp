class compare{
    public:
   bool operator()(const pair<int,int>&x,const pair<int,int>&y){
      return x.first <= y.first && x.second >= y.second;
  }  
};

class Solution {
public:
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> doable;
        multiset<pair<int,int>>undoable;
        
        // insert
        for(int i=0;i<profits.size();i++){
            int prof=profits[i];
            int cap=capital[i];
            if(prof>0){
                if(cap<=w){
                    doable.push(prof);
                }else{
                    undoable.insert({cap,prof});
                }
            }
        }
        // now try to maximize the capital
        while(k-- && doable.size()){
            // first work on doable
            w+=doable.top();
            doable.pop();
            
            // now add undoables to doables
            for(auto e=undoable.begin();undoable.size();e++){
                if(e->first<=w){
                    doable.push(e->second);
                    undoable.erase(e);
                }else{
                    break;
                }
            }
        }
        return w;
    }
};
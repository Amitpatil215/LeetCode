class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>won;
        unordered_map<int,int>lost;
        
        for(auto m:matches){
            int winner = m[0];
            int loser = m[1];
            //mark as participated
            won[winner] +=1;
            lost[loser]+=1;
        }
        
        vector<vector<int>>ans(2,vector<int>());
        for(auto winner:won){
            if(lost[winner.first]==0){
                ans[0].push_back(winner.first);
            }
        }
        for(auto loser:lost){
            if(loser.second==1){
                ans[1].push_back(loser.first);
            }
        }
        
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};
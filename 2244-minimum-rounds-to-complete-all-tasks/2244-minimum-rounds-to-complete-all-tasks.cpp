class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>freq;
        for(auto x:tasks){
            freq[x]++;
        }
        int rounds=0;
        for(auto f:freq){
            int val = f.second;
            if(val==1){
                return -1;
            }else if(val%3==0){
                rounds+=val/3;
            }else{
                rounds+=val/3;
                val=val%3;
                rounds+=val/2;
                val=val%2;
                if(val==1){
                    rounds+=1;
                }
            }
        }
        return rounds;
    }
};
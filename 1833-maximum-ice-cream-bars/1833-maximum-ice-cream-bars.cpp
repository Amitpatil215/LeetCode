class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum=0, count=0;
        for(auto x:costs){
            if(sum+x<=coins){
                sum+=x;
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};
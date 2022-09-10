class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
       sort(properties.begin(),properties.end(),[](vector<int>&v1, vector<int>&v2){
           if(v1[0]==v2[0]){
               return v1[1] > v2[1];
           }
           return v1[0] < v2[0];
       });
        int n = (int)properties.size();
        int maxDiffense = properties[n-1][1];
        int ans=0;
        for(int i=n-2; i>=0; i--){
            if(maxDiffense > properties[i][1])
                ans++;
            maxDiffense = max(maxDiffense, properties[i][1]);
        }
    return ans;
    }
};
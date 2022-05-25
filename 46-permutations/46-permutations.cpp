class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        queue<vector<int>> permutaions;
        permutaions.push({});
        
        for(int cur:nums){
            int n=permutaions.size();
            for(int i=0;i<n;i++){
                vector<int> oldPerm=permutaions.front();
                permutaions.pop();
                for(int j=0;j<=oldPerm.size();j++){
                    vector<int> newPerm=oldPerm;
                    newPerm.insert(newPerm.begin()+j,cur);
                    if(newPerm.size()==nums.size()){
                        results.push_back(newPerm);
                    }else{
                        permutaions.push(newPerm);
                    }
                }
            }
        }
        return results;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> back =ans.back();
            int earlierRowSize=ans.back().size();
            vector<int> currRow;
            currRow.push_back(back[0]);
            for(int j=1; j<earlierRowSize;j++){
                currRow.push_back(back[j]+back[j-1]);
            }
            currRow.push_back(1);
            ans.push_back(currRow);
        }
        return ans;
    }
    
};
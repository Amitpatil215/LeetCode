class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> back = ans.back();
            int a=back[0], b=back[1];
            int c=intervals[i][0],d=intervals[i][1];
            
            if(c>b){
                ans.push_back(intervals[i]);
            }else if(c<=b){
                ans.back()[1]=max(b,d);
            }
        }
        return ans;
    }
};



























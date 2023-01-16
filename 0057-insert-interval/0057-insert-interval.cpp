class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[0] <= v2[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            auto x = intervals[i];
            int si = ans.back()[0];//1
            int ei = ans.back()[1]; //5
            int nsi =x[0];//6
            int nei =x[1];//9
            vector<int>p;
            if(nsi>=si && nsi<=ei){
                ans.pop_back();
                p.push_back(si);
                p.push_back(max(nei,ei));
                ans.push_back(p);
            }else{
                ans.push_back(x);
            }
        }
        return  ans;
    }
};
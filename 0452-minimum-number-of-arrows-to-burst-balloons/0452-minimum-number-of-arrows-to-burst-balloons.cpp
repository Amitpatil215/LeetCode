class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        set<pair<int,int>>s;
        sort(points.begin(),points.end(),cmp);
        int count=1, currPos=points[0][1];
        for(int i=1;i<points.size();i++){
            int st = points[i][0];
            int en = points[i][1];
            if(currPos >=st && currPos<=en){
                continue;
            }else{
                currPos = en;
                count++;
            }
        }
        return count;
    }
};
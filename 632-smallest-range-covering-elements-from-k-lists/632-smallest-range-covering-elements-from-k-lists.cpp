class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        
        int rangeStart=0, rangeEnd=INT_MAX,
            currentMaxNo=INT_MIN;
        
        // insert
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            currentMaxNo=max(nums[i][0],currentMaxNo);
        }
        
        
        
        
        while(pq.size()==nums.size()){
            auto top=pq.top();
            pq.pop();
            
            int e = top.first;
            int i =top.second.first;
            
            if(rangeEnd-rangeStart > currentMaxNo-e){
                rangeEnd=currentMaxNo;
                rangeStart=e;
            }
            
            
            // push next element from same row
            if(nums[i].size()-1>=top.second.second+1){
                int newVal=nums[i][top.second.second+1];
                pq.push({newVal,{i,top.second.second+1}});
                
                 currentMaxNo=max(newVal,currentMaxNo);
            }
        }
        
        vector<int>ans(2);
        ans[0]=rangeStart;
        ans[1]=rangeEnd;
        return ans;
    }
};
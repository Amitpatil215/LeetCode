class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        // insert
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
        }
        
        // store sorted nums with their respective row
        vector<pair<int,int>> arr;
        
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            
            int e = top.first;
            int i =top.second.first;
            
            arr.push_back({e,i});
            
            // push next element from same row
            if(nums[i].size()-1>=top.second.second+1){
                int newVal=nums[i][top.second.second+1];
                pq.push({newVal,{i,top.second.second+1}});
            }
        }
        
        // apply sliding window to get the minimum range interval 
        int si=0;
        int n=arr.size();
        unordered_map<int,int>rows;
        int minInterValSize=INT_MAX;
        vector<int> ans(2);
        for(int i=0;i<n;i++){
            int element= arr[i].first;
            int row= arr[i].second;
            
            rows[row]++;
            // cout<<"inserted"<<element <<endl;
            
            while(rows.size()==nums.size()){
                int intervalSize=abs(arr[si].first-element);
                if(minInterValSize > intervalSize){
                    
                    minInterValSize=intervalSize;
                    ans[0]=arr[si].first;
                    ans[1]=element;
                    // cout<<minInterValSize<<" b/w "<<ans[0]<<" "<<ans[1]<<endl;
                }
                 //shrink the window
                 rows[arr[si].second]--;
                 if(rows[arr[si].second]==0){
                     rows.erase(arr[si].second);
                 }
                // cout<<"erased"<<arr[si].first<<endl;
                 si++;
                // cout<<si<<endl;
                // cout<<"rows size"<<rows.size()<<endl;
                    
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
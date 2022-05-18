class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,pair<int,int>>freq;
        vector<int> ans;
        // find frequency
        for(int i=0;i<nums.size();i++){
            if(freq.count(nums[i])>0){
                freq[nums[i]]={freq[nums[i]].first+1,nums[i]};    
            }else{
                freq[nums[i]]={1,nums[i]};
            }
        }
        
        //find top k
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<pair<int,int>> arr;    
        for(auto m:freq){
            arr.push_back(m.second);
        }
        
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        for(int i=k;i<arr.size();i++){
            if(arr[i].first>pq.top().first){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
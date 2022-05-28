class compare{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.first+a.second < b.first+b.second;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int> &nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>maxpq;
        
        for(int i=0; i< nums1.size();i++){
            for(int j=0; j< nums2.size();j++){
                if(maxpq.size()<k){
                    maxpq.push({nums1[i],nums2[j]});
                }else{
                    auto top=maxpq.top();
                    
                    if(nums1[i]+nums2[j] < top.first+top.second){
                        maxpq.pop();
                        maxpq.push({nums1[i],nums2[j]});
                    }else{
                        // if we couldn't able to find min sum pair than our top element
                        // then we can break as we know array are sorted in incresing order
                        break;
                    }
                }
            }
        }
        
        vector<vector<int>>ans;
        while(!maxpq.empty()){
            vector<int>sub;
            auto top=maxpq.top();
            maxpq.pop();
            
            sub.push_back(top.first);
            sub.push_back(top.second);
            ans.push_back(sub);
        }
        
        return ans;
    }
};
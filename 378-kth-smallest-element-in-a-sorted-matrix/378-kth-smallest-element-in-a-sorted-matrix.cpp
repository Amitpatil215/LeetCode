class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
                priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        // insert inital elements;
        for(int i=0;i<matrix.size();i++){
            pq.push({matrix[i][0],{i,0}});
        }
        int i=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            i++;

            if(k==i){
                return top.first;
            }
            
            //push next element from the same row
            if(matrix[top.second.first].size()-1>=top.second.second+1){
                int e=matrix[top.second.first][top.second.second+1];
                pq.push({e,{top.second.first,top.second.second+1}});
            }
        }
        
        return -1;
    }
};
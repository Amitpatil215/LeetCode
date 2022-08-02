class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minpq;
        // add first element of all the rows i.e. first column
        int n = matrix.size();
        for(int i=0;i<n;i++){
            minpq.push({matrix[i][0],{i,0}});
        }
        
        for(int i=0;i<k-1;i++){
            auto top = minpq.top(); // ith smallest element
            minpq.pop();
            //push the next element from same row
            int x =top.second.first;
            int y =top.second.second+1;
            if(y<n)
            minpq.push({matrix[x][y],{x,y}});
        }
        return minpq.top().first;
    }
};
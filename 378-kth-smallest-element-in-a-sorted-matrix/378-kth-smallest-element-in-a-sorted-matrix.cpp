class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>maxpq;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int num = matrix[i][j];
                if(maxpq.size()<k){
                    maxpq.push(num);    
                }else{
                    if(maxpq.top() > num){
                        maxpq.pop();
                        maxpq.push(num);
                    }
                }
            }
        }
        return maxpq.top();
        
    }
};
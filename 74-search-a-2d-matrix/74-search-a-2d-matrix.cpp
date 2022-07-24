class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =matrix.size();
        int m = matrix[0].size();
        
        int x=0,y=0;
        while(x<n-1 && matrix[x+1][y]<=target){
            x++;
        }
        // cout<<x<<endl;
        for(int i=0; i<m;i++){
            if(matrix[x][i]==target){
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =matrix.size();
        int m = matrix[0].size();
        
        
        /// reach to a row where the element lies
        int x=0,y=0;
        while(x<n-1 && matrix[x+1][y]<=target){
            x++;
        }
        
        /// linear search to find the element
        /* 
        for(int i=0; i<m;i++){
            if(matrix[x][i]==target){
            return true;
            }
        }
        */
        
        // instead we can apply lower bound i.e. we can leverage binary seach
        
        int index = lower_bound(matrix[x].begin(),matrix[x].end(),target) - matrix[x].begin();
        if(index!=m && matrix[x][index]==target){
            return true;
        }
        return false;
    }
};
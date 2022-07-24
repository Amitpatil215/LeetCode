class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = 0;
        int col = m-1;
        // start from the right top
        // if top-right val is greater than target then we cant find value in that column so -> col--
        // if top-right val is less than target then that means we cant find in the row so -> row++
        // if top-right val is equal to target then return
        while(row <n && col>=0){
            if(matrix[row][col]>target){
                col --;
            }else if(matrix[row][col]<target){
                row++;
            }else{
                return true;
            }
        }
        return false;
    }
};
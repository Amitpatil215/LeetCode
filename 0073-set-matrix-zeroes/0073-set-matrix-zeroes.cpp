class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        bool isRow=false, isCol =false;
        
        
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0){
                isRow=true;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                isCol=true;
                break;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1; j<m;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        //modifying the matrix
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        //modify first row and col
        if(isRow)
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        
        if(isCol)
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        
    }
};
class Solution {
public:
    bool check(int x,int y,int n,int m){
        return x>=0 && x<n && y>=0 && y<m; 
    }
    
    bool dfs(int x, int y,int index, vector<vector<char>>& board, string &word,vector<vector<bool>>&visited){
        if(index==word.size()-1){
            return true;
        }else if(index>=word.size()){
            return false;
        }
        int row[] = {-1,0,1,0};
        int col[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int xx=x+row[i];
            int yy=y+col[i];
            int n=board.size();
            int m=board[0].size();
            if(check(xx,yy,n,m) && !visited[xx][yy] && board[xx][yy]==word[index+1] && !visited[xx][yy]){
                visited[xx][yy]=true;
                if(dfs(xx,yy,index+1,board,word,visited)){
                    return true;
                }
                visited[xx][yy]=false;
            }

        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
                    visited[i][j]=true;
                    if(dfs(i,j,0,board,word,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
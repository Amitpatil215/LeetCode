// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool isValid(int i, int j, vector<vector<char>>& grid,vector<vector<bool>> &visited){
      int Row = grid.size();
      int Col = grid[0].size();
      return i>=0 && i<Row && j>=0 && j<Col && grid[i][j]=='1' && !visited[i][j];
  }
  void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &visited){
      visited[i][j] = true;
      
      int row[]={-1,-1,-1,0,0,1,1,1};
      int col[]={-1,0,1,-1,1,-1,0,1};
      
      int n=grid.size();
      int m = grid[0].size();
        
        for(int k=0; k<8; k++){
            if(isValid(i+row[k],j+col[k],grid,visited)){
                dfs(i+row[k],j+col[k],grid,visited);
            }
        }
    

      
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
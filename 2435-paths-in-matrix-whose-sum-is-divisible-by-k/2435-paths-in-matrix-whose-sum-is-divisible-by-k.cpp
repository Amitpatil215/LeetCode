class Solution {
public:
    int mod = (1e9) + 7;
    int util(int x,int y,long long int sum, vector<vector<int>>&grid, int &k, vector<vector<vector<int>>>&dp){
        if(x==0 && y==0) {
            return (sum+grid[x][y]) % k == 0;
        }
        if(x<0 || y<0) return 0;
        
        if(dp[x][y][sum]!=-1){
            return dp[x][y][sum];
        }
        
        int down = util(x-1,y,(sum+grid[x][y])%k,grid,k,dp)%mod;
        int right = util(x,y-1,(sum+grid[x][y])%k,grid,k,dp)%mod;
        return dp[x][y][sum]=(down + right )%mod; 
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // unordered_map<int,unordered_map<int,unordered_map<long long int,int>>>dp;
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>> (grid[0].size(),vector<int>((k+1),-1)));
        return util(grid.size()-1,grid[0].size()-1,0,grid,k,dp);
    }
};
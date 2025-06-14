class Solution {
  public:
    int helper(vector<vector<int>> &grid, int i, int j, int m, int n,vector<vector<int>> &dp){
        if(i==m-1 &&  j==n-1)
        return 1;
        if(grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down=0, right=0;
        
        if(i+1<m)
        down=helper(grid, i+1, j, m, n, dp);
        if(j+1<n)
        right=helper(grid, i, j+1, m, n, dp);
        return dp[i][j]=down+right;
        
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n, -1));
        return helper(grid, 0, 0, m, n, dp);
    }
};
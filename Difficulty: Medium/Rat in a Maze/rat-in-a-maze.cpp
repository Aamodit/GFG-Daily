class Solution {
  public:
    vector<string>ans;
    void solve(string &temp,int i,int j,vector<vector<int>>&maze,vector<vector<int>>&vis,int n)
    {
        
        if(i==n-1 && j==n-1)
        {
            ans.push_back(temp);
            return;
        }
          
        if(i+1<n && maze[i+1][j]==1 && vis[i+1][j]==1)
        {
            temp.push_back('D');
            vis[i+1][j]=0;
            solve(temp,i+1,j,maze,vis,n);
            temp.pop_back();
            vis[i+1][j]=1;
        }
        if(i-1>=0 && maze[i-1][j]==1 && vis[i-1][j]==1)
        {
            temp.push_back('U');
            vis[i-1][j]=0;
            solve(temp,i-1,j,maze,vis,n);
            temp.pop_back();
            vis[i-1][j]=1;
        }
        if(j+1<n && maze[i][j+1]==1 && vis[i][j+1]==1)
        {
            temp.push_back('R');
            vis[i][j+1]=0;
            solve(temp,i,j+1,maze,vis,n);
            temp.pop_back();
            vis[i][j+1]=1;
        }
        if(j-1>=0 && maze[i][j-1]==1 && vis[i][j-1]==1)
        {
            temp.push_back('L');
            vis[i][j-1]=0;
            solve(temp,i,j-1,maze,vis,n);
            temp.pop_back();
            vis[i][j-1]=1;
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        ans.clear();
        
        if (maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans;
        
        vector<vector<int>> vis(n, vector<int>(n, 1));
        string temp = "";
        
        vis[0][0] = 0;
        solve(temp,0,0,maze,vis,n);
          
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
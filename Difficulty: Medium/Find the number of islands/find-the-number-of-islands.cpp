//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
int r;
    int c;
    int row[8]={-1,-1,-1,1,1,1,0,0};
    int col[8]={-1,0,1,-1,0,1,-1,1};
    bool valid(int i,int j){
        return i>=0&&i<r&&j>=0&&j<c;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        r=grid.size();
        c= grid[0].size();
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1') {
                    count++;
                    q.push(make_pair(i,j));
                    grid[i][j]='0';
                    while(!q.empty())
                    {
                        int new_i=q.front().first;
                        int new_j=q.front().second;
                        q.pop();
                        for(int k=0;k<8;k++){
                            if(valid(new_i+row[k],new_j+col[k])&&grid[new_i+row[k]][new_j+col[k]]=='1'){
                                 grid[new_i+row[k]][new_j+col[k]]='0';
                                 q.push(make_pair(new_i+row[k],new_j+col[k]));
                            }
                        }
                    }
                }
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends
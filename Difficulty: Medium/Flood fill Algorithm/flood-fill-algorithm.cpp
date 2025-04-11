//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int row[4] = {0,-1,0,1};
    int col[4] = {-1,0,1,0};
  public:
    bool isSafe(int r,int c,vector<vector<int>>& image)
    {
        return r >= 0 && r < image.size() && c >= 0 && c < image[0].size();
    }
    void solve(int r, int c, int newColor, int oldColor,vector<vector<int>>& image)
    {
        image[r][c] = newColor;
        for(int k=0; k<4; k++)
        {
            if(isSafe(r+row[k], c+col[k], image) && image[r+row[k]][c+col[k]] == oldColor)
            {
                solve(r+row[k], c+col[k] , newColor, oldColor,image);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor) {
        
        int oldColor = image[sr][sc];
        
        if(newColor == oldColor) return image;
        
        solve(sr,sc,newColor,oldColor,image);
        
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
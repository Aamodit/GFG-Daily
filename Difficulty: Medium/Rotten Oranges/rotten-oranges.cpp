//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void checkNeighbours(pair<pair<int, int>, int> temp, vector<vector<int>>& mat, queue<pair<pair<int, int>, int>>& q) {
    int x = temp.first.first, y = temp.first.second, time = temp.second;
    int rows = mat.size(), cols = mat[0].size();

    // Up
    if (x - 1 >= 0 && mat[x - 1][y] == 1) {
        q.push({{x - 1, y}, time + 1});
        mat[x - 1][y] = 2;
    }

    // Down
    if (x + 1 < rows && mat[x + 1][y] == 1) {
        q.push({{x + 1, y}, time + 1});
        mat[x + 1][y] = 2;
    }

    // Left
    if (y - 1 >= 0 && mat[x][y - 1] == 1) {
        q.push({{x, y - 1}, time + 1});
        mat[x][y - 1] = 2;
    }

    // Right
    if (y + 1 < cols && mat[x][y + 1] == 1) {
        q.push({{x, y + 1}, time + 1});
        mat[x][y + 1] = 2;
    }
}

// Function to find the minimum time required to rot all oranges.
int orangesRotting(vector<vector<int>>& mat) {
    queue<pair<pair<int, int>, int>> q;
    int ans = 0, rows = mat.size(), cols = mat[0].size();

    // Pushing all the rotten oranges into the queue
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) { // FIXED: Changed `i++` to `j++`
            if (mat[i][j] == 2) {
                q.push({{i, j}, 0});
            }
        }
    }

    // BFS to track all the oranges getting rotten
    while (!q.empty()) {
        auto temp = q.front();
        ans = temp.second;
        q.pop();
        checkNeighbours(temp, mat, q);
    }

    // Check if there are any fresh oranges left
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 1) return -1; // If any fresh orange is left, return -1
        }
    }

    return ans;
}
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
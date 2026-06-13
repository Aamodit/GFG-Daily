class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0, j = 0;
        int dir = 0; // 0=Right, 1=Down, 2=Left, 3=Up

        while (true) {
            if (mat[i][j] == 1) {
                dir = (dir + 1) % 4; // turn right
                mat[i][j] = 0;
            }

            // move in current direction
            if (dir == 0) j++;
            else if (dir == 1) i++;
            else if (dir == 2) j--;
            else i--;

            // check if exited matrix
            if (i < 0) return {0, j};
            if (j < 0) return {i, 0};
            if (i >= n) return {n - 1, j};
            if (j >= m) return {i, m - 1};
        }
    }
};
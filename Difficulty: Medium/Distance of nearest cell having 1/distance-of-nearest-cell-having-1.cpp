class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                if(mat[i][j] == 1) q.push({i, j});
            }
        }
        
        int dist = 0;
        
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                
                mat[i][j] = dist == 0 ? -1e9 : dist;
                
                if(i-1 >= 0 and mat[i-1][j] == 0) {
                    q.push({i-1,j});
                    mat[i-1][j] = -1e9;
                } 
                
                if(j-1 >= 0 and mat[i][j-1] == 0) {
                    q.push({i,j-1});
                    mat[i][j-1] = -1e9;
                } 
                
                if(i+1 < mat.size() and mat[i+1][j] == 0) {
                    q.push({i+1,j});
                    mat[i+1][j] = -1e9;
                } 
                
                if(j+1 < mat[0].size() and mat[i][j+1] == 0) {
                    q.push({i,j+1});
                    mat[i][j+1] = -1e9;
                }
            }
            dist++;
        }
        
        for(auto &vec : mat) {
            for(auto &ele : vec) {
                if(ele == -1e9) ele = 0;
            }
        }

        return mat;
    }
};
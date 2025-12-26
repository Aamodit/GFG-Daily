struct Cmp{
  vector<vector<int>> *mat;
  Cmp(vector<vector<int>> &m){
      mat = &m;
  }
    
  bool operator()(pair<int, int> &a, pair<int, int> &b){
      if((*mat)[b.first][b.second] < (*mat)[a.first][a.second])
        return true;
      return false;    
  }  
};


class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        Cmp cmp(mat);      
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> minHeap(cmp);
        vector<vector<bool>> visited(n, vector<bool>(n, false)); 
        
        minHeap.push({0, 0});
        visited[0][0] = true;
        
        
        while(!minHeap.empty()){
          auto z = minHeap.top();
          minHeap.pop();
          k--;
          if(k==0)
            return mat[z.first][z.second];
            
          int i = z.first;
          int j = z.second;
          
          int rj = j+1;
          if(i<n && rj<n && (!visited[i][rj])){
              minHeap.push({i, rj});
              visited[i][rj] = true;
          }
          
          int di = i+1;
          if(di<n && j<n && (!visited[di][j])){
              minHeap.push({di, j});
              visited[di][j] = true;
          }
          
        }
        
        
        return -1;
        
    }
};
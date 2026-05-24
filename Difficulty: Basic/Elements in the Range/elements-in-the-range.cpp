class Solution {
  public:
    virtual bool checkElements(int start, int end, vector<int> &arr){
      unordered_map<int, bool> visited;
      for(int x: arr) visited[x]=true;
      
      
      for(int i=start; i<=end; i++){
        if(!visited[i]) return false; 
      }
      
      return true;
    }
};
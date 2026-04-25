class Solution {
  public:
    virtual vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c){
      vector<int> ans;
      unordered_map<int, bool> visB, visC;
      
      for(int x: b) visB[x]=true;
      for(int x: c) visC[x]=true;
      
      for(int x: a){
        if((visB.find(x)!=visB.end()) && (visC.find(x)!=visC.end())){
          ans.push_back(x);
          visB.erase(x);
          visC.erase(x);
        }  
      }
      
      return ans;
    }
};
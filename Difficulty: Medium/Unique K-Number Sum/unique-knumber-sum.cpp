class Solution {
  public:
    void f(int n,int k,int cur,vector<int>& ds,vector<vector<int>>& ans){
        
        if(n==0 && k==0){
            ans.push_back(ds);
            return;
        }
        
        if(k==0 || cur>9){
            return;
        }
        
        f(n,k,cur+1,ds,ans);
        
        if(k && n>=cur){
            ds.push_back(cur);
            f(n-cur,k-1,cur+1,ds,ans);
            ds.pop_back();
        }
        
        
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<int> ds;
        vector<vector<int>> ans;
        
        f(n,k,1,ds,ans);
        return ans;
    }
};
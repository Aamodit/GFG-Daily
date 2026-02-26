class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<long long>> pref(n+1,vector<long long>(m+1,0));
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pref[i][j]=mat[i-1][j-1] 
                            + pref[i-1][j] 
                            + pref[i][j-1] 
                            - pref[i-1][j-1];
            }
        }
        
        int cnt=0;
        
        
        for(int k=1;k<=min(n,m);k++){
            for(int i=0;i+k-1<n;i++){
                for(int j=0;j+k-1<m;j++){
                    
                    int r1=i,c1=j;
                    int r2=i+k-1,c2=j+k-1;
                    
                    long long sum=pref[r2+1][c2+1]
                                  - pref[r1][c2+1]
                                  - pref[r2+1][c1]
                                  + pref[r1][c1];
                    
                    
                    if(sum==x){
                        cnt++;
                    }              
                    
                }
            }
        }
        
        return cnt;
        
    }
};
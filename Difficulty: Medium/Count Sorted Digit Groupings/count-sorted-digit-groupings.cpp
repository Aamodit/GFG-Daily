class Solution {
  public:
  int dp[105][1000];
    int validGroups(string &s) {
        // code here
        
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        auto f=[&] (auto&&f,int i,int prev)->int{
            if(i==n) return 1;
            
            if(dp[i][prev+1]!=-1)  return dp[i][prev+1];
            int sum = 0;
            int ans=0;
            for(int j=i;j<n;j++){
                sum += s[j]-'0';
                if(sum>=prev){
                    ans+=f(f,j+1,sum);
                }
            }
            
            return dp[i][prev+1]=ans;
            
        };
        
        return f(f,0,-1);
    }
};
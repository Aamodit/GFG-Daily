class Solution {
  public:
    int mod=1e9+7;
    int solve(int i, int j, int n, int m, string  &s, string &t, vector<vector<int>>&dp){

        if(j==m){
            return 1;
        }
        if(i==n){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;

        if(s[i]==t[j]){
            ans=(ans+solve(i+1, j+1, n, m, s, t, dp))%mod;
        }

        ans=(ans+solve(i+1, j, n, m, s, t, dp))%mod;

        return dp[i][j]=ans;
    }

    int countWays(string &s1, string &s2) {
        // code here
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, s1, s2, dp);

    }
};

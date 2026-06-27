class Solution {
    private:
    const int mod= 1e9 + 7;
    int get_ans(int i, int n, int m, vector<int> &dp){
        if(i<n)return dp[i]=1;
        if(i==m) return dp[i]=2;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=(get_ans(i-1, n, m, dp) + get_ans(i-m, n,  m, dp)) % mod;
    }
  public:
    int countWays(int n, int m) {
  vector<int > dp(n+1, -1);
        // code here. 
        return get_ans(n, m, m, dp)%mod;
    }
};


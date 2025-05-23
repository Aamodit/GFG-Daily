class Solution {
  public:
    int lcs(int i, int j, string &s, string &s2, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == s2[j])
            return dp[i][j] = 1+lcs(i-1, j-1, s, s2, dp);
        return dp[i][j] = max(lcs(i-1, j, s, s2, dp), lcs(i, j-1, s, s2, dp));
    }
  
    int minDeletions(string s) {
        // code here
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return n - lcs(n-1, n-1, s, s2, dp);
    }
};
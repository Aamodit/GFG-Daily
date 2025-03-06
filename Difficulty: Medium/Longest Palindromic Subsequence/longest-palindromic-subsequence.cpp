//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int find(int i,int j,int n,int m,string &s1,string &s2, vector<vector<int>>&dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=1+find(i+1,j+1,n,m,s1,s2,dp);
        }
        else{
            return dp[i][j]=max(find(i+1,j,n,m,s1,s2,dp),find(i,j+1,n,m,s1,s2,dp));
        }
    }
    int longestPalinSubseq(string &s) {
        string A=s;
        string B=s;
        reverse(B.begin(),B.end());
        int n=A.size();
        int m=B.size();
        int i=0;
        int j=0;
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      return find(i,j,n,m,A,B,dp);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
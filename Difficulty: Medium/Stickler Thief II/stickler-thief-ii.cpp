//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,int n,vector<int>& arr){
        if(i>=n)return 0;
        int inc=arr[i]+solve(i+2,n,arr);
        int exc=solve(i+1,n,arr);
        return max(inc,exc);
    }
    int solveMem(int i,int n,vector<int>& arr,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1) return dp[i];
        int inc=arr[i]+solveMem(i+2,n,arr,dp);
        int exc=solveMem(i+1,n,arr,dp);
        return dp[i]=max(inc,exc);
    }
    int solveTab(vector<int>& arr,int s,int e){
          vector<int>dp(e+1,0);
          for(int i=e-1;i>=s;i--){
              int inc=arr[i];
              if(i+2<e)inc+=dp[i+2];
              int exc=dp[i+1];
            dp[i]=max(inc,exc);
          }
          return dp[s];
    }
    int solveSpace(vector<int>& arr,int s,int e){
          int curr=0,next1=0,next2=0;
          for(int i=e-1;i>=s;i--){
              int inc=arr[i];
              if(i+2<e)inc+=next2;
              int exc=next1;
              int curr=max(inc,exc);
            next2=next1;
            next1=curr;
          }
          return next1;
    }
    int maxValue(vector<int>& arr) {
        // arr.push_back(arr[0]);
        int n=arr.size();
        // return max(solve(0,n-1,arr),solve(1,n,arr));
        vector<int>dp1(n+1,-1),dp2(n+1,-1);
        // int left=solveMem(0,n-1,arr,dp1);
        // int right=solveMem(1,n,arr,dp2);
        // int left=solveTab(arr,0,n-1);
        // int right=solveTab(arr,1,n);
        int left=solveSpace(arr,0,n-1);
        int right=solveSpace(arr,1,n);
        return max(left,right);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
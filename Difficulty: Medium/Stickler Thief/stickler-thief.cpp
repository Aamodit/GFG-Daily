//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,vector<int>& arr){
        if(i>=arr.size())return 0;
        int inc=arr[i]+solve(i+2,arr);
        int exc=solve(i+1,arr);
        return max(inc,exc);
    }
    
    int solveMem(int i,vector<int>& arr,vector<int>&dp){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1) return dp[i];
        int inc=arr[i]+solveMem(i+2,arr,dp);
        int exc=solveMem(i+1,arr,dp);
        return dp[i]=max(inc,exc);
    }
    int solveTab(vector<int>&arr){
       vector<int>dp(arr.size()+1,0);
       for(int i=arr.size()-1;i>=0;i--){
            int inc=arr[i];
            if(i+2<arr.size())inc+=dp[i+2];
            int exc=dp[i+1];
            dp[i]=max(inc,exc);
       } 
        return dp[0];
    }
    int solveSpa(vector<int>&arr){
       int curr=0,next1=0,next2=0; 
       for(int i=arr.size()-1;i>=0;i--){
            int inc=arr[i];
            if(i+2<arr.size())inc+=next2;
            int exc=next1;
            curr=max(inc,exc);
            next2=next1;
            next1=curr;
       } 
        return next1;
    }
    int findMaxSum(vector<int>& arr) {
        // return solve(0,arr);
        vector<int>dp(arr.size()+1,-1);
        // return solveMem(0,arr,dp);
        // return solveTab(arr);
        return solveSpa(arr);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
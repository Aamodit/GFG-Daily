//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int help(int n ,int ind,vector<int> a , vector<vector<int>>  &dp){
        if(ind==0){
            
               if(n%a[0]){
                   return -1e9;
               }
               else{
                   return n/a[0];
               }
            
        }
        //if(ind < 0 )return -1e9 ;
        if(n==0)return 0;
        if(dp[n][ind]!=-1) return dp[n][ind];
        int take = -1e9 , nott = help(n,ind-1,a,dp);
        if(a[ind]<=n){
            take = 1 + help(n-a[ind],ind,a,dp);
        }
        return dp[n][ind] = max(take,nott);
        
    }

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> a(3);
        a[0]=x;a[1]=y;a[2]=z;
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        int ans = help(n,2,a,dp);
        return  0>ans?0:ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
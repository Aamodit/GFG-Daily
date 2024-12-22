//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool checkrow(vector<vector<int>> mat,int i,int m,int x){
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(x==mat[i][mid])return true;
            else if(x<mat[i][mid])high=mid-1;
            else low=mid+1;
        }
        return false;
    }
     bool checkcol(vector<vector<int>> mat,int i,int n,int x){
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(x==mat[mid][i])return true;
            else if(x<mat[mid][i])high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            if(mat[i][0]<=x && mat[i][m-1]>=x){
              bool found=  checkrow(mat,i,m,x);
              if(found)return true;
            }
        }
         for(int i=0;i<m;i++){
            if(mat[0][i]<=x && mat[n-1][0]>=x){
              bool found=  checkcol(mat,i,n,x);
              if(found)return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
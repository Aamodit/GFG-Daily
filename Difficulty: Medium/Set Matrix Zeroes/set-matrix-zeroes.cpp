//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here

    set<int>change_columns;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));  //set all values to '0'
        for(int i=0; i<n; i++)
        {
            int flag=0;
            for(int j=0; j<m; j++ )
            {
                if(mat[i][j]==0)   //check if zero present in the row or not
                {
                    change_columns.insert(j);  //If '0' i spresent store the coulumn
                    flag=1;
                }
                
            }
            if(flag==0) ans[i]=mat[i];  // If '0' is not present in the row replace the ans row with the orginal matrix row
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(change_columns.find(j)!=change_columns.end()) //If coulumn is found in the set change the value to zero
                {
                    ans[i][j]=0;
                }
            }
        }
        mat=ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
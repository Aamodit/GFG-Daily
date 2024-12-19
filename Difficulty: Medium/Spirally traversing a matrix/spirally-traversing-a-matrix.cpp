//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int up=0,left=0,right=m-1,down=n-1;
        vector<int>ans;
        while(left<=right && up<=down){
            for(int i=left;i<=right;i++){
                ans.push_back(mat[up][i]);
            }
            up++;
            for(int i=up;i<=down;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            if(up<=down){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[down][i]);
            }
            down--;
            }
            if(left<=right){
            for(int i=down;i>=up;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
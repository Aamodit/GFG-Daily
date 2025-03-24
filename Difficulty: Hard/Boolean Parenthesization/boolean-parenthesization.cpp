//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
public:
    int countWays(string &s) {
        int n = s.size();
        
        // DP tables to store ways to evaluate to True and False
        vector<vector<int>> T(n, vector<int>(n, 0));
        vector<vector<int>> F(n, vector<int>(n, 0));

        // Initialize base cases for single characters
        for (int i = 0; i < n; i += 2) {
            T[i][i] = (s[i] == 'T') ? 1 : 0;
            F[i][i] = (s[i] == 'F') ? 1 : 0;
        }

        // DP logic for subexpressions of increasing length
        for (int length = 3; length <= n; length += 2) {
            for (int i = 0; i <= n - length; i += 2) {
                int j = i + length - 1;

                for (int k = i + 1; k < j; k += 2) {
                    char op = s[k];

                    // Left and right subexpression counts
                    int leftT = T[i][k - 1];
                    int leftF = F[i][k - 1];
                    int rightT = T[k + 1][j];
                    int rightF = F[k + 1][j];

                    if (op == '&') {
                        T[i][j] += leftT * rightT;
                        F[i][j] += (leftF * rightF) + (leftT * rightF) + (leftF * rightT);
                    } 
                    else if (op == '|') {
                        T[i][j] += (leftT * rightT) + (leftT * rightF) + (leftF * rightT);
                        F[i][j] += leftF * rightF;
                    } 
                    else if (op == '^') {
                        T[i][j] += (leftT * rightF) + (leftF * rightT);
                        F[i][j] += (leftT * rightT) + (leftF * rightF);
                    }
                }
            }
        }

        // Return the number of ways the whole expression evaluates to True
        return T[0][n - 1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
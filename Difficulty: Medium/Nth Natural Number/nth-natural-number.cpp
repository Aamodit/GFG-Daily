//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        vector<int> base9;
        long long ans = 0;
        while(n) {
            base9.push_back(n%9);
            n /= 9;
        }
        reverse(base9.begin(), base9.end());
        
        for(int x : base9) {
            ans *= 10;
            ans += x;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends
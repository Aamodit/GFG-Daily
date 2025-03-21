//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countgroup(vector<int>& arr) {
        int n = arr.size();
        int x = 0, r = 1;
        
        for (int i = 0; i < n; ++i) {
            x ^= arr[i];
        }
        
        if (x != 0) {
            return 0;
        }
        
        while (--n) {
            r = r * 2 % 1000000007;
        }
        
        return --r;
    }
};





//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends
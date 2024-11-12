//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Sort the array
        sort(arr.begin(), arr.end());
        
        int increments = 0;
        
        for (int i = 1; i < arr.size(); ++i) {
            // If current element is not greater than the previous one
            if (arr[i] <= arr[i - 1]) {
                int new_value = arr[i - 1] + 1;
                increments += new_value - arr[i]; // Number of increments needed
                arr[i] = new_value; // Update the current element to be unique
            }
        }
        
        return increments;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
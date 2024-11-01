//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int n = arr.size();
    int limit = min(n, k + 1);  // Limit to check within bounds

    // Check the first 'k' (or 'n') elements for duplicates
    for (int i = 0; i < limit; i++) {
        if (++freq[arr[i]] > 1)
            return true;
    }

    // Slide the window for the rest of the vector
    for (int i = k + 1; i < n; i++) {
        --freq[arr[i - k - 1]];  // Remove the element that's out of the window
        if (++freq[arr[i]] > 1)  // Check the new element
            return true;
    }
    return false;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Helper function to check if it's possible to place cows with at least `mindis` distance
    bool cowplace(vector<int>& stalls, int mindis, int k) {
        int count = 1; // Place the first cow
        int lastpos = stalls[0]; // Position of the last placed cow

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastpos >= mindis) {
                count++; // Place another cow
                lastpos = stalls[i]; // Update last placed position
                if (count == k) {
                    return true; // Successfully placed all cows
                }
            }
        }
        return false; // Not possible to place all cows with `mindis`
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end()); // Sort stall positions

        int l = 1; // Minimum distance
        int r = stalls[stalls.size() - 1] - stalls[0]; // Maximum possible distance
        int res = 0; // Store the result

        while (l <= r) {
            int mid = l + (r - l) / 2; // Calculate mid distance
            if (cowplace(stalls, mid, k)) {
                res = mid; // Update result if possible
                l = mid + 1; // Try for a larger minimum distance
            } else {
                r = mid - 1; // Try for a smaller minimum distance
            }
        }
        return res; // Return the largest minimum distance
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
         int n = arr.size();
        unordered_map<int, int> mp;
        int siz = 0;
    
        for (int i = 0; i < n; i++) {
            int maxi = arr[i], mini = arr[i];
            int s = 0;
            for (int j = i; j < n; j++) {
                maxi = max(maxi, arr[j]);
                mini = min(mini, arr[j]);
    
                if (maxi - mini > x) {
                    break;
                }
                s = j - i + 1; 
            }
    
            if (s > siz) {
                siz = s;
                mp[siz] = i; 
            } else if (s == siz) {
                mp[siz] = min(mp[siz], i); 
            }
        }
    
        vector<int> v;
        for (int i = mp[siz]; i < mp[siz] + siz; i++) { 
            v.push_back(arr[i]);
        }

    return v;
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
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> lMax(n, 0);
        lMax[0] = arr[0];
        for(int i=1;i<n;i++){
            lMax[i] = max(lMax[i-1],  arr[i]);     
        }
        
        vector<int> rMax(n, 0);
        rMax[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            rMax[i] = max(rMax[i+1], arr[i]);
        }
        
        for(int i=0;i<n;i++){
            if(lMax[i] == rMax[i])
                return lMax[i];
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
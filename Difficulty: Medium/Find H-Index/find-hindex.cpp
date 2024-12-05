//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        int maxE = 0;
        for(auto &e : citations){
            maxE = max(e, maxE);
        }
        vector<int> mp (maxE + 1, 0);
        for(auto &e : citations){
            mp[e]++;
        }
        if(mp[maxE] >= maxE){
            return maxE;
        }
        for(int i = maxE  - 1; i >= 0; i--){
            mp[i] += mp[i + 1];
            if(mp[i] >= i){
                return i;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
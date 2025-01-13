//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
    int sum = 0, lsum = 0;

    // Calculate the total sum of the array
    for (auto &num : arr)
        sum += num;

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        // Before adding arr[i] to lsum, check if it's an equilibrium point
        if (lsum == sum - arr[i])
            return i;

        // Update lsum and reduce sum for the next iteration
        lsum += arr[i];
        sum -= arr[i];
    }

    return -1; // No equilibrium point found
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
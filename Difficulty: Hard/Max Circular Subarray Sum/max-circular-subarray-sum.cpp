//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
 int circularSubarraySum(vector<int> &arr) {

        // your code here
        int big = INT_MIN, sum = 0, curr=0;
        
        for(int i = 0; i<arr.size(); ++i)
        {
            curr += arr[i];
            sum += arr[i];
            big = max(big, curr);
            
            if(curr < 0)
                curr = 0;
        }
        
        curr = 0;
        for(int i = 0; i<arr.size(); ++i)
        {
            curr += arr[i];
            big = max(big, sum - curr);
            
            if(curr > 0)
                curr = 0;
        }
        
        return big;
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
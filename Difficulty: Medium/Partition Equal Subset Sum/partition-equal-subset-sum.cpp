//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solveTab(int sum,vector<int>& arr)
    {
        int n = arr.size();
        vector<bool>next(sum+1,0);
        vector<bool>curr(sum+1,0);
        
            next[0] = 1;
        
        for(int index=n-1; index>=0; index--)
        {
            for(int i=0; i<=sum; i++)
            {
                if(i-arr[index] >= 0 && arr[index] <= i && next[i-arr[index]])
                    curr[i] = 1;
                    
                else
                    curr[i] = next[i];
            }
            next = curr;
        }
        return next[sum];
    }
    
    bool equalPartition(vector<int>& arr) {
        int sum = 0;
        for(num : arr)
            sum += num;
        if(sum % 2 != 0) return 0;
        sum /= 2;
        
        return solveTab(sum,arr);

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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
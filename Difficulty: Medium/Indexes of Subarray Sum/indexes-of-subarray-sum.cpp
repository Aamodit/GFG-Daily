//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
       vector<int> subarraySum(vector<int> &arr, int target) {
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        vector<int> ans(2, -1);
        
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            int k = sum - target;
            if(mp.find(k) != mp.end()){
                int start = mp[k] + 2;
                int end = i + 1;
                ans[0] = start;
                ans[1] = end;
                return ans;
            }
            mp[sum] = i;
        }
        
        ans.pop_back();
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends
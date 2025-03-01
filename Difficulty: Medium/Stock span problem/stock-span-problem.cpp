//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here 
        stack<int> st;
        for(int i=0; i<arr.size(); i++) {
            int c = 1;
            int span = 0;
            int idx = i;
           while(!st.empty() && st.top()<=arr[i]) {
               st.pop();
               idx = idx-c;
               span+=arr[idx];
               c = arr[idx];
            }
           st.push(arr[i]);
           arr[i] = span+1;
        }
        return arr;
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
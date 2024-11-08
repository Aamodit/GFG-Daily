//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string compute(string &s1, string &s2) {
        if (s1.size() < s2.size()) swap(s1, s2);
    
        int n1 = s1.size(), n2 = s2.size();
        int carry = 0;
        string res = "";
    
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
    
        for (int i = 0; i < n1; i++) {
            int val1 = s1[i] - '0';
            int val2 = i < n2 ? s2[i] - '0' : 0;
    
            int sum = val1 + val2 + carry;
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        if (carry) res.push_back(carry + '0');
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    string minSum(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int index =0;
        auto it =upper_bound(arr.begin(),arr.end(),0);
        if(it == arr.end()){
            return to_string(0);
        }
        index= it -arr.begin();
        string f = "", s = "";
    
        for (int i = index; i < n; i++) {
            if (i % 2 == 0) {
                f += to_string(arr[i]);
            } else {
                s += to_string(arr[i]);
            }
        }
    
        return compute(f, s);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
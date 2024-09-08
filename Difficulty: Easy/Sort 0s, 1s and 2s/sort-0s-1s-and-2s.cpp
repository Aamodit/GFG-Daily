//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        int idx = 0;
        while(idx <= j){
            if(arr[idx] == 0){
                swap(arr[idx], arr[i]);
                i++;
                idx++;
            }else if(arr[idx] == 2){
                swap(arr[idx], arr[j]);
                j--;
            }else{
                idx++;
            }
        }
        return;
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
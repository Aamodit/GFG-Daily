//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
    int n = arr.size();
    if (n < 2) return 0;

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int trapped_water = 0;

    while (left <= right) {
        if (arr[left] < arr[right]) {
            if (arr[left] > left_max) {
                left_max = arr[left];
            } else {
                trapped_water += left_max - arr[left];
            }
            left++;
        } else {
            if (arr[right] > right_max) {
                right_max = arr[right];
            } else {
                trapped_water += right_max - arr[right];
            }
            right--;
        }
    }

    return trapped_water;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
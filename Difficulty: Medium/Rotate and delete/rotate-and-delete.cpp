//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
               int k = 1;  // Operation count starts from 1
        
        while (arr.size() > 1) {
            
            // Rotate the array right by 1 position
            int temp = arr.back();  
            arr.pop_back();        
            arr.insert(arr.begin(), temp);  
    
            // Index to remove (n - k + 1) => (arr.size() - k)
            int index_to_remove = arr.size() - k;
            if(index_to_remove < 0) //negative -> 0
                index_to_remove = 0;
                
            // Remove the element
            arr.erase(arr.begin() + index_to_remove);
    
            // Increment operation count
            k++;
        }
        
        return arr[0];
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
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
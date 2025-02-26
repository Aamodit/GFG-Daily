//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int mini;
  stack<pair<int,int>>s;

//use a pair<int,int> to keep track of the top element and the minimum //bottom upto top of stack
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(!s.empty())
        {
            int mini = s.top().second;
            s.push({x,min(mini,x)});
        }
        else
        {
            s.push({x,x});
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!s.empty())
        {
            s.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(s.empty())
        return -1;
        return s.top().first;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!s.empty())
        {
            return s.top().second;
            
        }
        else
        {
            return -1;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
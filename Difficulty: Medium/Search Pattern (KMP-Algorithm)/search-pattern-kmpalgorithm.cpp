//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to compute the Longest Prefix Suffix (LPS) array
    void computeLPS(string& pat, vector<int>& lps) {
        int m = pat.size();
        int len = 0; // Length of the previous longest prefix suffix
        lps[0] = 0;  // LPS of the first character is always 0
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // Use the previous LPS value
                } else {
                    lps[i] = 0; // No prefix-suffix match
                    i++;
                }
            }
        }
    }

    // Function to search pattern in the given text using the KMP algorithm
    vector<int> search(string& pat, string& txt) {
        int n = txt.size();
        int m = pat.size();
        vector<int> lps(m, 0); // LPS array
        vector<int> indices;  // To store the starting indices of matches

        // Compute the LPS array
        computeLPS(pat, lps);

        int i = 0; // Index for txt
        int j = 0; // Index for pat

        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) { // Pattern found
                indices.push_back(i - j);
                j = lps[j - 1]; // Move to the next possible match
            } else if (i < n && pat[j] != txt[i]) { // Mismatch
                if (j != 0) {
                    j = lps[j - 1]; // Use LPS to skip comparisons
                } else {
                    i++; // Move to the next character in txt
                }
            }
        }

        return indices;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
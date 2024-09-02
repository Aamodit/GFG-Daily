//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    // create two dimensional matrix len1 x len2
	    // each cell represent the longest matching string of str1 in str2
	    // the matrix is 1 based in order to use 0 length
	    int n = str1.size();
	    int m = str2.size();
	    vector<vector<int>> vc(n+1, vector<int>(m+1, 0));
	    
	    // i - loop through characters of str1
	    for(int i=0; i<n; i++)
	    {
	        // j - loop through characters of str2
	        for(int j=0; j<m; j++)
	        {
	            // when characters equal, increase longest common subsequence
	            if(str1[i] == str2[j])
	            {
	                vc[i+1][j+1] = vc[i][j] + 1;
	            }
	            // when characters not equal, choose greater chiose
	            // vc[i+1][j] means deletion (not using character i of str1)
	            // vc[i][j+1] means insertion (adding character j of str2)
	            else
	            {
	                vc[i+1][j+1] = max(vc[i+1][j], vc[i][j+1]);
	            }
	        }
	    }
	    // vc[n][m] is LCS (longest common subsequence)
	    // characters to insert n - LCS
	    // characters to delete m - LCS
	    return n - vc[n][m] + m - vc[n][m];
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
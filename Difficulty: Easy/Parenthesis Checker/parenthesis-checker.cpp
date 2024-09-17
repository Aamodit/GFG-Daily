//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        for(auto i:x){
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
            }else{
                if(st.empty()) return 0;
                if(i==')' && st.top()=='(' || i=='}' && st.top()=='{' || i==']' && st.top()=='[') st.pop();
                else return 0;
            }
        }
        return st.size()==0;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
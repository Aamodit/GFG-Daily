class Solution {
  public:
int findIndex(string& str) {
        // Your code goes here
        int n =str.length();
        int open=0; int close=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]==')')
            close++;
        }
        for(int i=0;i<=n;++i)
        {
            if(open == close)
            return i;
            if(i<n)
            {
            if(str[i]==')')
            close--;
            if(str[i]=='(')
            open++;
            }
        }
        return -1;
    }


};
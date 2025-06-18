class Solution {
  public:
    string caseSort(string& str) {
        // code here
        string ans="";
        
        string small="";
        string big="";
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>=65 && str[i]<=90)
            {
                big+=str[i];
            }
            else
            {
                small+=str[i];
            }
            
        }
        sort(small.begin(),small.end());
        sort(big.begin(),big.end());
        int ctr1=0,ctr2=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>=65 && str[i]<=90)
            {
                ans+=big[ctr1++];
            }
            else
            {
                ans+=small[ctr2++];
            }
        }
        return ans;
    }
};
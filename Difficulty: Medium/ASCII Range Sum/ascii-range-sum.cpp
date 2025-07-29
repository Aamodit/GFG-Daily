class Solution {
  public:
   vector<int> asciirange(string& s) 
    {
        vector<int> first(26,-1);
        vector<int> last(26,-1);
        vector<int> sum;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(first[s[i] - 'a'] == -1)
            {
                first[s[i] - 'a'] = i;
                last[s[i] - 'a'] = i;
            }
            else
            {
                last[s[i] - 'a'] = i;
            }
        }
        
        for(int i = 0; i < 26; i++)
        {
            int temp = 0;
            if(first[i] != -1 and first[i] < last[i])
            {
                for(int j = first[i] + 1; j < last[i]; j++)
                {
                    temp += s[j];
                }
                if(temp)
                    sum.push_back(temp);
            }
        }
        
        return sum;
        // code here
        
    }
};
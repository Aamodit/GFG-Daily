class Solution {
  public:
   int flag=0;
    bool areIsomorphic(string &s1, string &s2) {
        int i;
        int count=0;
       if (s1.size() != s2.size())
        return false;
        unordered_map <char,char> m;
        for(i=0;i<s1.size();i++){
            m[s1[i]]=s2[i];
        }
       
        for(i=0;i<s1.size();i++)
        {
            if(m[s1[i]]==s2[i])
            {
               
                flag=1;
                
            }
            else return false;     
        }
        if(flag==1){
           
            unordered_map <char,char> m1;
            unordered_map <char,char> m2;
            for(i=0;i<s1.size();i++){
                m1[s1[i]]=s2[i];
            }
            for(i=0;i<s1.size();i++){
                m2[s2[i]]=s1[i];
            }
            if(m1.size()==m2.size())
                return true;
            else
                return false;
        }
    }
};
class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        unordered_map<char,int>freq;
        queue<char>q;
        string result="";
        
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            freq[ch]++;
            q.push(ch);
            
            
            while(!q.empty()){
                char firstelement=q.front();
                
                if(freq[firstelement]==1){
                    result.push_back(firstelement);
                    break;
                }
                else{
                    q.pop();
                }
            }
            if(q.empty()){
                result.push_back('#');
            }
            
        }
        return result;
        
    }
};


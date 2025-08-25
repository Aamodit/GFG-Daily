class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
      size_t pos=0; 
      for(char c: s1){ pos=s2.find(c,pos); if(pos==string::npos) return false; ++pos; } 
      return true;

    }
};
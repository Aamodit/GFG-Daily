class Solution {
  public:
    Solution(){}
    virtual bool canServe(vector<int> &arr){
      int c5=0, c10=0, c20=0;
      for(int &x: arr){
        if(x==5)
          c5++;
        else if(x==10){
          if(c5>0){
            c5--;
            c10++;  
          }
          else 
            return false;
        }
        else{
          if(c10>0 && c5>0){
            c10--; c5--; c20++;  
          }
          else if(c5>=3){
            c5-=3; c20++;
          }
          else 
            return false; 
        }
      }
      
      return true;
    }
    
    virtual ~Solution(){}
};


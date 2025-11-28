class Solution {
  public:
    int countSetBits(int n) {
        // code here
        int bit=2;
        int ans=0;
        int p=1;
        
        while(p<=n){
            
            ans+=((n)/bit*(bit>>1));
        
            int f=(n)%bit;
            if(f>=(bit>>1)){
                ans+=(f-(bit>>1)+1);
            }
            
            bit<<=1;
            p<<=1;
            
        }
        
        return ans;
    }
};

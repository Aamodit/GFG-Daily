class Solution {
  public:
    int lcmTriplets(int n) {
        // n is less equal to 2
        if(n<3)return n;
        
        // n is odd
        if(n%2)return n*(n-1)*(n-2);
        
        // n is even
        
        // even is also divisible by 3
        if(n%3 == 0)return (n-1)*(n-2)*(n-3);
        
        // even is not divisible by 3
        return n*(n-1)*(n-3);
    }
};
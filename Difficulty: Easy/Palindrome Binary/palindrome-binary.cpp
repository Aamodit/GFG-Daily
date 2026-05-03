 class Solution {
  public:
    int isPallindrome(long long int N) {
        // code here
        long long int sum=0,rem;
        long long int temp=N;
        string str="";
        while(temp>0){
            rem=temp%2;
            str+=rem+'0';
            temp=temp/2;
        }
        string ishu=str;
        reverse(str.begin(),str.end());
        if(ishu==str){
            return 1;
        }
        return 0;
    }
};


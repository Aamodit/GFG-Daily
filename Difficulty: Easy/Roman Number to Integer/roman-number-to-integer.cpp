class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
         int n=s.size();
        vector<int> a;
       
        for(int i=n-1;i>=0;i--){
            if(s[i]=='I') a.push_back(1);
            if(s[i]=='V') a.push_back(5);
            if(s[i]=='X') a.push_back(10);
             if(s[i]=='L') a.push_back(50);
            if(s[i]=='C') a.push_back(100);
            if(s[i]=='D') a.push_back(500);
             if(s[i]=='M') a.push_back(1000);
            
        }
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<endl;
        // }
        int ans = a[0];
        for(int i=1;i<n;i++){
            if(a[i-1]>a[i]){
                ans-=a[i];
                continue;
            }
            ans+=a[i];
            
        }
        return ans;
    }
};
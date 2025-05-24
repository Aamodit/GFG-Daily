class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
    int n = arr.size();
    int maxi = *max_element(arr.begin(),arr.end());
    vector<bool> vis(maxi+1,false);
    for(int e : arr)
    vis[e] = true;
    
       for(int a = 1;a<= maxi; a++)
       {
           if(vis[a])
           {
               for(int b = 1;b<=maxi;b++)
               {
                   if(vis[b])
                   {
                       int c = sqrt(a*a + b*b);
                       if((c*c != (a*a + b*b)))
                       continue;
                       if(c>maxi)
                       continue;
                       if(vis[c])
                       return true;
                   }
               }
           }
       }
       return false;
    }


};
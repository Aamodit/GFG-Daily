class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int left=0;
        int right=0;
        int flips=0;
        int len=0;
        while(right<n)
        {
            if(arr[right]==0)
            {
                flips++;
            }
            while(flips>k)
            {
                if(arr[left]==0)
                {
                    flips--;
                }
                left++;
            }
            len=max(len,right-left+1);
            right++;
            
        }
        return len;
        
    }
};
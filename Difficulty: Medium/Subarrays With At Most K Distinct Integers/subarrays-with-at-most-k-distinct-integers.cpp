class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int left = 0, right = 0, count = 0;
        unordered_map<int, int> freq;

        for (right = 0; right < arr.size(); ++right) {
            // If it's a new unique element, reduce k
            if (freq[arr[right]] == 0) {
                k--;
            }
            freq[arr[right]]++;

            // Shrink window if more than k distinct elements
            while (k < 0) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    k++;
                }
                left++;
            }

            // Count subarrays ending at right
            count += right - left + 1;
        }

        return count;
    }
};

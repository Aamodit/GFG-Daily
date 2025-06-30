class Solution {
  public:
    int substrCount(string &s, int k) {
        if (k > s.size()) return 0;

        unordered_map<char, int> freq;
        int count = 0;

        // Initialize the first window
        for (int i = 0; i < k; ++i) {
            freq[s[i]]++;
        }
        if (freq.size() == k - 1) count++;

        // Slide the window
        for (int i = k; i < s.size(); ++i) {
            char charOut = s[i - k];
            char charIn = s[i];

            // Remove the outgoing character
            freq[charOut]--;
            if (freq[charOut] == 0) {
                freq.erase(charOut);
            }

            // Add the incoming character
            freq[charIn]++;

            // Check if there are exactly k - 1 distinct characters
            if (freq.size() == k - 1) count++;
        }

        return count;
    }
};

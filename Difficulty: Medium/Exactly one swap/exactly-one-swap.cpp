class Solution {
  public:
    int countStrings(string &s) {
        // code here
         int n = s.size();
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
    long long total_pairs = 1LL * n * (n - 1) / 2;
    long long same_pairs = 0;

    for (auto& p : freq) {
        same_pairs += 1LL * p.second * (p.second - 1) / 2;
    }

    long long result = total_pairs - same_pairs;

    // If all characters are unique, result is total_pairs
    // Else we can make one redundant swap (like 'a' with 'a')
    if (same_pairs > 0) result += 1;

    return result;
    }
};

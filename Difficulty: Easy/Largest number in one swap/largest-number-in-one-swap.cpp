class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        int maxIdx = n - 1; // keep track of the max char index from the right
        int swap_i = -1, swap_j = -1;

        // traverse from right to left
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] < s[maxIdx]) {
                swap_i = i;
                swap_j = maxIdx;
            } else if (s[i] > s[maxIdx]) {
                maxIdx = i; // update max character index
            }
        }

        // if a swap is possible
        if (swap_i != -1) {
            swap(s[swap_i], s[swap_j]);
        }

        return s;
    }
};
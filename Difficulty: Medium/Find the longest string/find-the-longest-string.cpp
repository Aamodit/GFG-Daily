class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd = false;

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool allPrefixesExist(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            node = node->children[idx];
            if (!node || !node->isEnd)
                return false;
        }
        return true;
    }

    string longestString(vector<string>& arr) {
        for (const string& word : arr)
            insert(word);

        string result = "";

        for (const string& word : arr) {
            if (allPrefixesExist(word)) {
                if (word.length() > result.length() ||
                   (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }

        return result;
    }
};

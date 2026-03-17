/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int ans = 0;
    int solve(Node* root){
        if(!root)return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        ans += abs((root->data+left+right) - 1);
        return (root->data+left+right)-1;
    }
    int distCandy(Node* root) {
        solve(root);
        return ans;
    }
};
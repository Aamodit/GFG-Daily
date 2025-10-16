/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    void revInorder(Node* root, int& sum){
        if(!root) return;
        revInorder(root->right,sum);
        int temp=root->data;
        root->data=sum;
        sum+=temp;
        revInorder(root->left,sum);
    }
    void transformTree(Node *root) {
        int sum=0;
        revInorder(root, sum);
    }
};
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
    private:
    int getAns(Node* root, unordered_map<Node*,int> &dp){
        if(!root){
            return 0;
        }
        if(dp.find(root)!=dp.end())
        return dp[root];
        int include=root->data;
        if(root->left){
            include= include+ getAns(root->left->left, dp) + getAns(root->left->right, dp); 
        }
        if(root->right){
            include= include+ getAns(root->right->left, dp) + getAns(root->right->right, dp);
        }
        // ab exclude bhi karo do sath  meijn
        int exclude=0;
            exclude=exclude+getAns(root->left, dp);
        
      
            exclude+= getAns(root->right, dp);
        
        int finalAns= max(include, exclude);
        return dp[root]=finalAns;
    }
  public:
    int getMaxSum(Node *root) {
        //  code here
        unordered_map<Node*, int>dp;
        
        return getAns(root, dp);
        
    }
};
/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  private:
    bool is_leaf(Node* node){
        return (!node->left && !node->right);
    }
  public:
    bool isDeadEnd(Node *root) {
        // Code here
        unordered_set<int> present;
        queue<Node*> q, leaves;
        q.push(root);

        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            present.insert(curr->data);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

            if(is_leaf(curr)) leaves.push(curr);
        }

        while(!leaves.empty()){
            Node* curr = leaves.front();    leaves.pop();
           
            int val = curr->data;
            //left_child;
            bool lc = 0;
            if(val>1 && present.find(val-1) == present.end()) lc = 1;
           
            //right_child
            bool rc = 0;
            if(present.find(val+1) == present.end()) rc = 1;

            if(!lc && !rc) return 1;
        }
        return 0;
    }
};

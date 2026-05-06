class Solution {
public:
    Node* find(Node* root, Node* subRoot, vector<Node*>& arr) {
        if (!root)
            return nullptr;

        if (root->data == subRoot->data) {
            arr.push_back(root);
        }

        if (find(root->left, subRoot, arr))
            return find(root->left, subRoot, arr);
        else
            return find(root->right, subRoot, arr);
    }

    bool is(Node* a, Node* b) {
        if (!a && !b)
            return true;

        if ((a && !b) || (!a && b))
            return false;

        if (a->data != b->data)
            return false;

        return is(a->left, b->left) && is(a->right, b->right);
    }

    bool isSubTree(Node* root, Node* subRoot) {
        vector<Node*> arr;

        Node* temp = find(root, subRoot, arr);

        for (int i = 0; i < arr.size(); i++) {
            if (is(arr[i], subRoot))
                return true;
        }

        return false;
    }
};
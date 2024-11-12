//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
vector<int> traverse(Node* root, long long& accumulator)
    {
        if(!root) return {};
        else
        {
            vector<int> oleft = traverse(root->left, accumulator);
            vector<int> oright = traverse(root->right, accumulator);
            
            if(oleft.size()==0 && oright.size()==0)
            {
                accumulator += (root->data);
                return {1};
            }
            else
            {
                vector<int> out = {0};
                int i=0, j=0;
                while(i<oleft.size() && j<oright.size())
                {
                    out.push_back(oleft[i++] + oright[j++]);
                    accumulator += ((root->data) * ((long long)out[i] * (long long)pow(10,i)));
                }
                while(i<oleft.size())
                {
                    out.push_back(oleft[i++]);
                    accumulator += ((root->data) * ((long long)out[i] * (long long)pow(10,i)));
                }
                while(j<oright.size())
                {
                    out.push_back(oright[j++]);
                    accumulator += ((root->data) * ((long long)out[j] * (long long)pow(10,j)));
                }
                return out;
            }
        }
}
    
int treePathsSum(Node *root) {
        long long accumulator = 0;
        traverse(root, accumulator);
        return accumulator;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.treePathsSum(root);
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
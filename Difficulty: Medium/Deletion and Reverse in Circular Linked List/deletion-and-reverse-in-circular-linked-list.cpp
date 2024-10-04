//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
Node* reverse(Node* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* temp = head;
        Node* prevNode = NULL;
        while(temp->next != head){
            temp = temp->next;
        }
        prevNode = temp;
        temp = head;
        Node* nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
        while(temp != head){
        nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
        }
        return prevNode;
    }


    Node* deleteNode(Node* head, int key) {
        
        Node* temp = head->next;
        if(head -> data == key){
            while(temp->next != head){
                temp = temp->next;
            }
            Node* toDel = temp->next;
            temp->next = head->next;
            head = head->next;
            toDel->next = NULL;
            delete toDel;
            return head;
        }
        if(head->next->data == key){
            Node* curr = head->next;
            head->next = curr->next;
            curr->next = NULL;
            delete curr;
            return head;
        }
        while(temp != head){
            if(temp->next->data == key){
                Node* curr = temp->next;
                temp->next = curr->next;
                curr->next = NULL;
                delete curr;
                break;
            }
            temp = temp->next;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
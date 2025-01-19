//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends
/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {


        // use dummy node to make your life easier


        Node* dummy = new Node(-1);
        Node* dummyHead = dummy;
        Node* curr1 = head1;
        Node* curr2 = head2;
        
        while(curr1 && curr2){


            // point dummyHead to the correct node .


            if(curr1->data < curr2->data){
                dummyHead->next = curr1;
                dummyHead = curr1;
                curr1 = curr1->next;
            }else{
                dummyHead->next = curr2;
                dummyHead = curr2;
                curr2 = curr2->next;
            }
        }


        // when coming out of loop that means either of curr1
        // or curr2 is NULL then no need to sort any further just
        // link the dummyHead with the rest of list which is not null


        if(!curr1){
            dummyHead -> next = curr2;
        }
        if(!curr2){
            dummyHead -> next = curr1;
        }


        // dummy node was for our help , now betray him by deleting and 
        // pointing to first node(i.e. head of merged list).


        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
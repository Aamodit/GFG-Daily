//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node*reverse(Node*head){
        Node*curr=head;
        Node*prev=NULL;
        Node*next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
         if(head->data==9&&head->next==NULL){
            Node*newNode=new Node(0);
            head->data=1;
            head->next=newNode;
            return head;
        }
        if(head->next==NULL){
            head->data=head->data+1;
            return head;
        }
        head=reverse(head);
        int carry=0;
        Node*temp=head;
        int val=carry+1+temp->data;
        carry=val/10;
        temp->data=val%10;
        temp=temp->next;
        while(temp->next!=NULL&&carry!=0){
            val=carry+temp->data;
            carry=val/10;
            temp->data=val%10;
            temp=temp->next;
        }
         val=temp->data+carry;
         carry=val/10;
         temp->data=val%10;
        if(carry!=0){
            Node*newNode=new Node(carry);
            temp->next=newNode;
        }
         head=reverse(head);
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
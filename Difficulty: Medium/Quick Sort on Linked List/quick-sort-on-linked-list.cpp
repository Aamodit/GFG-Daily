//{ Driver Code Starts
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Partitions the list taking the last element as the pivot
struct Node* partition(struct Node* head, struct Node* end, struct Node*& newHead,
                       struct Node*& newEnd) {
    struct Node* pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the pivot - becomes the new head
            if (newHead == NULL)
                newHead = cur;

            prev = cur;
            cur = cur->next;
        } else { // If cur node is greater than pivot
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list, pivot becomes the
    // head
    if (newHead == NULL)
        newHead = pivot;

    // Update newEnd to the current last node
    newEnd = tail;

    // Return the pivot node
    return pivot;
}


// } Driver Code Ends

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
  public:
    // partition function divide the list arround the first element
    // minimum length - 2 elemetns
    struct Node* partition(struct Node* first, struct Node* last) {
        // two pointers runs through the list comparing with the head
        // p1 currently checked node
        // p2 swaps if smaller than the pivot
        Node* p1 = first;
        Node* p2 = first;
        // loop until the last
        while(p1 != last)
        {
            // compare p1 with pivot
            if(p1->data < first->data)
            {
                swap(p1->data, p2->next->data);
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        // increase p2 and swap with pivot
        swap(p2->data, first->data);
        return p2;
    }
    
    // sortList function finds partition of the list
    // and recursively sort the two halves
    void sortList(struct Node* first, struct Node* last) {
        if(first && first != last)
        {
            // find partition arround first element
            Node* prt = partition(first, last);
            
            // recursive call to two halves of the list
            // make sure more then one element left
            sortList(first, prt);
            sortList(prt->next, last);
        }
    }
    
    struct Node* quickSort(struct Node* head) {
        // The approach is to create two funcion of quick sort
        // 1. partition functuin that receives begin + end pointers
        //    the function partitions the elements on sides of first
        //    and returns its new position
        // 2. sortList function that receives begin + end elements
        //    partition the first element
        //    sort begin - partition
        //    sort partition->next - end
        
        sortList(head, NULL);
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

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
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
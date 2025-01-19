//{ Driver Code Starts
// Initial Template for C++
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
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

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
    Node* rotate(Node* head, int k) {
        // Handle edge cases
        if (!head || !head->next || k == 0) {
            return head;
        }

        // Step 1: Find the length of the list
        Node* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        // Step 2: Handle cases where k >= length
        k = k % length;
        if (k == 0) {
            return head; // No rotation needed
        }

        // Step 3: Connect the last node to the head to form a circular list
        temp->next = head;

        // Step 4: Traverse to the (k-1)th node
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }

        // Step 5: Update the head and break the circular list
        Node* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    
    
    Node* segregate(Node *head) {
        if(head == NULL || head->next == NULL)
        return head;
        
        Node* dummy0 = new Node(-1); 
        Node* zeroHead = dummy0;
        
        Node* dummy1 = new Node(-1);
        Node* oneHead = dummy1;
        
        Node* dummy2 = new Node(-1);
        Node* twoHead = dummy2;
        
        Node* temp = head;
        
        while(temp != NULL){
            if(temp->data == 0){
                zeroHead->next = temp;
                zeroHead = zeroHead->next; // zeroHead = temp;
            }
            else if(temp->data == 1){
                oneHead->next = temp;
                oneHead = oneHead->next;
            }
            else{
                twoHead->next = temp;
                twoHead = twoHead->next;
            }
            temp = temp->next;
        }
        // if(oneHead->next != NULL){
        //     zeroHead->next = oneHead->next;
        // }
        // else {
        //     zeroHead->next = twoHead->next;
        // }
        zeroHead->next = (dummy1->next != NULL) ? dummy1->next : dummy2->next;
        oneHead->next = dummy2->next;
        twoHead->next = NULL;
        
        Node* newHead = dummy0->next;
        
        delete dummy0;
        delete dummy1;
        delete dummy2;
        
        return newHead;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

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

class Solution
{
    public:
    Node* reverseList(Node *head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while(curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverseList(head);
        Node* temp = head;
        
        
        int c = 1;
        while(temp != NULL)
        {
            temp->data += c;
            if(temp->data < 10 )
            {
                c = 0;
                break;
            }
            else
            {
                temp->data =0;
                c=1;
            }
            temp = temp->next;
        }
        if(c==1)
        {
            Node* newNode = new Node(1);
            head = reverseList(head);
            newNode->next = head;
              return newNode;
            
        }
      head = reverseList(head);
      return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
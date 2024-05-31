//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};


// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
        Node* curr = head_ref;
      //Your code here
      
      //if list is empty return NULL
      if(head_ref == NULL)
      return NULL;
      
      // rech to the element to be deleted
      for(int i =1; i<x && curr!=NULL ; i++){
          curr= curr->next;
      }
      
      // if element to be deleted is beyond the length
      if(curr == NULL)
      return head_ref;
      
      
      // if element to be deleted is head
      if(curr == head_ref){
          head_ref = curr->next;
          if(head_ref != NULL){
              head_ref->prev = NULL;
          }
          delete curr;
          return head_ref;
      }
      
      //id element to be deleted is in middle
      if(curr->next!= NULL){
          curr->next->prev = curr->prev;
          
      }
      if(curr->prev != NULL){
          curr->prev->next = curr->next;
      }
      
      // if elemet to be deleted is in end
    //   if(curr->next == NULL){
    //       curr->prev->next = NULL;
    //       curr->prev = NULL;
    //   }
      delete curr;
      
      return head_ref;
      
    }
};

//{ Driver Code Starts.

/* Function to print Nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node)
{
  while(node!=NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
   printf("\n");
}
 
/* Drier program to test above functions*/
int main()
{
  int t, x, n, i;
  scanf("%d",&t);
  
  while(t--)
  {
      /* Start with the empty list */
      struct Node *temp,*head = NULL;
      scanf("%d",&n);
      
      temp = NULL;
      
      for(i=0;i<n;i++){
        scanf("%d",&x);
        
        if(head == NULL){
            head = new Node(x);
            temp = head;
        }
        else{
            Node *temp1 = new Node(x);
            temp->next = temp1;
            temp1->prev = temp;
            temp = temp->next;
        }
      }
  
    scanf("%d",&x);
      
    Solution ob;  
    head = ob.deleteNode(head,x); 
      
        
        printList(head);           
        while(head->next!=NULL)
        {
    	    temp=head;
    	    head=head->next;
    	    free(temp);
    	}
    	
    	free(head);
	}
	return 0;
}

// } Driver Code Ends
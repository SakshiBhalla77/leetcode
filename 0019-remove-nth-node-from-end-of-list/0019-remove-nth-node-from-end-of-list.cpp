/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next == NULL)
        return NULL;

        int cnt = 0;
        ListNode* temp = head;
        while(temp!= NULL){
            cnt++;
            temp = temp->next;
        }
        
        // If the node to be removed is the head
        if(cnt == n){
        ListNode* newHead = head->next;
        delete head;
        return newHead;
        }

        int result = cnt  - n; //no of iterations that need to be performed
        temp = head;
        for(int i = 1; i < result; i++) {
            temp = temp->next;
        }


        ListNode* deleteNode = temp->next;
        temp->next = temp->next->next;
       
        delete deleteNode;
    

return head;

    }
};
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
    ListNode* mergeNodes(ListNode* head) 
    {
        if(head == 0 ) return NULL;

        ListNode* temp = NULL;
        ListNode* fast = head->next;
        ListNode* slow = head;

        int sum = 0;

        while(fast!=NULL)
        {
            if(fast->val !=0)
            sum = sum + fast->val;

            else{
                slow -> val = sum;
                temp = slow;
                slow = slow -> next;
                sum =0;
            }
            fast = fast -> next;

        }
        temp->next = 0;

        return head;

    }
};
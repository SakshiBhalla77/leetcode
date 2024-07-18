/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        //edge case
        if(node==NULL || node->next == NULL)
        return ;
        
        node->val = node->next->val;
        ListNode* NodeToDelete = node->next;

        node->next = node->next->next;
        delete NodeToDelete;



       

    }
};
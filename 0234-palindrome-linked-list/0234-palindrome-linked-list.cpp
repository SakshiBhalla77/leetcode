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

    ListNode* reverseHead(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        return head;

        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* next  = NULL;

        while(temp!=NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;

        }
        return prev;

    }


    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return true;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!= NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* reversedHead = reverseHead(slow);

        ListNode* first = head;
        ListNode* second = reversedHead;

        while(second!= NULL){
            if(first->val != second->val){
            reverseHead(reversedHead);
            return false;
        }
        first = first->next;
        second = second->next;
        
        }
        reverseHead(reversedHead);
            return true;
    }
};
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* next = NULL;

        while (temp != NULL) {
            next = temp->next; // storing the next node
            temp->next = prev; // replace the pointer
            prev = temp;
            temp = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
        }
        ListNode* reversedHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = reversedHead;

        while(second!=NULL){

            if(first->val != second->val ){
                reverseList(reversedHead);
                return false;
            }

             first = first->next;
            second = second->next;
            
        }
        reverseList(reversedHead);
        return true;
    }
};
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
ListNode* reverse(ListNode*head)
{
    ListNode* temp = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    while(temp!=NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;

    }
    return prev;
}

    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) return true;

        //find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* reversedHead = reverse(slow);

        ListNode* first = head;
        ListNode* second = reversedHead;

        while(second!=NULL){
            if(first->val != second->val){
                reverse(reversedHead);
                return false;
            }
            first = first->next;
            second = second->next;

        }
        reverse(reversedHead);
        return true;


    }
};
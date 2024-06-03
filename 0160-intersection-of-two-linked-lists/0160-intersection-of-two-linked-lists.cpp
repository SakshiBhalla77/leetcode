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
    // APPROACH ONE

    /*    int findLength(ListNode* head) {
            int c = 0;

            while (head != NULL) {
                c++;
                head = head->next;
            }
            return c;
        }
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            int a = findLength(headA);
            int b = findLength(headB);

            if (b > a) {
                for (int i = 0; i < (b - a); i++)
                    headB = headB->next;
            } else if (a > b) {
                for (int i = 0; i < (a - b); i++)
                    headA = headA->next;
            }

            while (headA != NULL && headB != NULL) {
                if (headA == headB) {
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
            return NULL;
        }
    }; */

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {
            if (temp1 != NULL)
                temp1 = temp1->next;

            else {
                temp1 = headB;
            }

            if (temp2 != NULL)
                temp2 = temp2->next;

            else 
                temp2 = headA;
            
            // temp1 = temp1 == NULL? headB:temp1->next;
            // temp2 = temp2 == NULL? headA:temp2->next;
        }
        return temp2; // return temp2 will work too
    }
};
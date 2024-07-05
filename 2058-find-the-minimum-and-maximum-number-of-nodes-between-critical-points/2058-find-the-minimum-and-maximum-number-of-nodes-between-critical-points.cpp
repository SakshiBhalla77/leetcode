#include <vector>
#include <climits>
using namespace std;

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1}; // Edge case: Less than 3 nodes

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* forward = curr->next;

        vector<int> criticalPoints;
        vector<int> result(2, -1); // To store the minimum and maximum distances

        int index = 1; // Start from the second node
        while (forward != nullptr) {
            if ((curr->val < prev->val && curr->val < forward->val) || 
                (curr->val > prev->val && curr->val > forward->val)) {
                criticalPoints.push_back(index);
            }

            prev = curr;
            curr = forward;
            forward = forward->next;
            index++;
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1}; // Less than 2 critical points
        }

        int minDist = INT_MAX;
        for (size_t i = 1; i < criticalPoints.size(); ++i) {
            minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
        }

        int maxDist = criticalPoints.back() - criticalPoints.front();
        result[0] = minDist;
        result[1] = maxDist;

        return result;
    }
};
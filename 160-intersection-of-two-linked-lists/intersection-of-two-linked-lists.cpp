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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> mpp;

        ListNode* temp = headA;

        while (temp != NULL) {
            mpp[temp] = 1;
            temp = temp->next;
        }

        ListNode* temp2 = headB;

        while (temp2 != NULL) {
            if (mpp.find(temp2) != mpp.end()) {
                return temp2;
            }

            temp2 = temp2->next;
        }

        return NULL;
    }
};
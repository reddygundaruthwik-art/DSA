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
private:
    ListNode* reverseHelper(ListNode* curr, ListNode* prev) {
        if (curr == nullptr) {
            return prev;
        }

        ListNode* nextNode = curr->next;
        curr->next = prev;

        return reverseHelper(nextNode, curr);
    }

public:
    ListNode* reverseList(ListNode* head) {
        return reverseHelper(head, nullptr);
    }
};

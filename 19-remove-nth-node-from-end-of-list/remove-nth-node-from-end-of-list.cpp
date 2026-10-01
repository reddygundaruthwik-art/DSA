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
        int cnt = 0;
        ListNode* temp = head;

        // Count total nodes
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        // If we have to remove the head
        if (n == cnt) {
            return head->next;
        }

        // Find the node just before the node to delete
        temp = head;

        int pos = cnt - n;

        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        // Delete the nth node from the end
        temp->next = temp->next->next;

        return head;
    }
};
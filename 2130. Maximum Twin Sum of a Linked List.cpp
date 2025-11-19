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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        int maximum = 0;

        while(fast) {
            fast = fast -> next -> next;
            ListNode* tmp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = tmp;
        }

        fast = slow;
        slow = prev;

        while(slow) {
            maximum = max(maximum, slow -> val + fast -> val);
            slow = slow -> next;
            fast = fast -> next;
        }

        return maximum;
    }
};
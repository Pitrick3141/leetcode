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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* current = head;
        int count = 0;
        while(current) {
            count ++;
            current = current -> next;
        }
        current = head;
        count = count / 2;

        if(count-- == 0) return head -> next;
        while(count--) {
            current = current -> next;
        }
        if(current -> next) current -> next = current -> next -> next;
        return head;
    }
};
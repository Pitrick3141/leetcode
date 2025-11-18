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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = nullptr;
        ListNode* oddHead = nullptr;
        ListNode* even = nullptr;
        ListNode* evenHead = nullptr;
        ListNode* current = head;
        bool isOdd = true;
        while(current) {
            if(isOdd) {
                if(odd) odd -> next = current;
                else oddHead = current;
                odd = current;
            }
            else {
                if(even) even -> next = current;
                else evenHead = current;
                even = current;
            }
            isOdd = !isOdd;
            current = current -> next;
        }
        if(odd) odd -> next = evenHead;
        if(even) even -> next = nullptr;
        return oddHead;
    }
};
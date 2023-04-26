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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* ret = head->next;
        
        ListNode* curr = head;
        ListNode* then = head->next;

        while (then) {
            ListNode* new_curr = then->next;
            ListNode* new_then = then->next ? then->next->next : then->next;
            curr->next = then->next ? then->next->next ? then->next->next : then->next : nullptr;
            then->next = curr;
            curr = new_curr;
            then = new_then;
        }

        return ret;
    }
};
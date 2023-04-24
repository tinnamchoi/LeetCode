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
    ListNode* ATN(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2) {
            return carry ? new ListNode(carry, nullptr) : nullptr;
        }
        int new_val;
        if (!l1) {
            new_val = l2->val + carry;
            return carry ? new ListNode(new_val % 10, ATN(nullptr, l2->next, new_val / 10)) : l2;
        }
        if (!l2) {
            new_val = l1->val + carry;
            return carry ? new ListNode(new_val % 10, ATN(nullptr, l1->next, new_val / 10)) : l1;
        }
        new_val = l1->val + l2->val + carry;
        return new ListNode(new_val % 10, ATN(l1->next, l2->next, new_val / 10));
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return ATN(l1, l2, 0);
    }
};
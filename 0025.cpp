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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> v;
        for (int i = 0; i < k; i++) {
            if (!head) {
                return v.size() ? v[0] : nullptr;
            }
            v.push_back(head);
            head = head->next;
        }
        v[0]->next = reverseKGroup(v[k - 1]->next, k);
        for (int i = 1; i < k; i++) {
            v[i]->next = v[i - 1];
        }
        return v[k - 1];
    }
};
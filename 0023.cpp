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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* tail = new ListNode();
        ListNode* head = tail;

        int n = lists.size();
        int remaining = lists.size();

        if (!n) {
            return nullptr;
        }
        for (ListNode* i : lists) {
            if (!i) {
                remaining--;
            }
        }

        while (remaining) {
            int min_node_index = -1;
            for (int i = 0; i < n; i++) {
                if (!lists[i]) {
                    continue;
                }
                if (min_node_index == -1 || lists[i]->val < lists[min_node_index]->val) {
                    min_node_index = i;
                }
            }
            tail->next = lists[min_node_index];
            tail = tail->next;
            lists[min_node_index] = lists[min_node_index]->next;
            if (!lists[min_node_index]) {
                remaining--;
            }
        }

        return head->next;
    }
};
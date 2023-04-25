/* Submission */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
            return false;
        }
        queue<TreeNode*> pq;
        queue<TreeNode*> qq;
        pq.push(p);
        qq.push(q);
        while (!pq.empty() && !qq.empty()) {
            TreeNode* pcurrent = pq.front();
            TreeNode* qcurrent = qq.front();
            if ((pcurrent == nullptr && qcurrent != nullptr) || (pcurrent != nullptr && qcurrent == nullptr)) {
                return false;
            }
            if ((pcurrent != nullptr && qcurrent != nullptr) && (pcurrent->val != qcurrent->val)) {
                return false;
            }
            pq.pop();
            qq.pop();
            if (pcurrent != nullptr) {
                pq.push(pcurrent->left);
                pq.push(pcurrent->right);
            }
            if (qcurrent != nullptr) {
                qq.push(qcurrent->left);
                qq.push(qcurrent->right);
            }
        }
        return true;
    }
};
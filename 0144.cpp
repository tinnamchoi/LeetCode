/* Binary Tree Preorder Traversal */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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


vector<int> DFS(TreeNode* current, vector<int> out) {
    if (current == nullptr) {
        return out;
    }
    out.push_back(current->val);
    out = DFS(current->left, out);
    out = DFS(current->right, out);
    return out;
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> out;
        out = DFS(root, out);
        return out;
    }
};
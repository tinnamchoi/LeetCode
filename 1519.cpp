/* Number of Nodes in the Sub-Tree With the Same Label */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
private:
    vector<int> dfs (int& current, int& parent, vector<vector<int>>& alist, string& labels, vector<int>& ans) {

        vector<int> count(26);
        for (int node : alist[current]) {
            if (node == parent) {continue;}
            vector<int> temp = dfs(node, current, alist, labels, ans);
            for (int i = 0; i < count.size(); i++) count[i] += temp[i];
        }
        
        count[labels[current] - 'a'] += 1;
        ans[current] = count[labels[current] - 'a'];
        return count;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<vector<int>> alist(n);
        for (vector<int> edge : edges) {
            alist[edge[0]].push_back(edge[1]);
            alist[edge[1]].push_back(edge[0]);
        }

        int current = 0;
        int parent = -1;
        vector<int> ans(n);

        dfs(current, parent, alist, labels, ans);

        return ans;
    }
};
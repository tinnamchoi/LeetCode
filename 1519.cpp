/* Number of Nodes in the Sub-Tree With the Same Label */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    vector<int> ans;
    string labels;
    vector<vector<int>> alist;

    vector<int> dfs(int current) {
        vector<int> count(26, 0);
        count[labels[current] - 97]++;
        for (int i : alist[current]) {
            vector<int> temp = dfs(i);
            for (int i = 0; i < 26; i++) {
                count[i] += temp[i];
            }
        }
        ans[current] = count[labels[current] - 97];
        return count;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this->labels = labels;
        ans.resize(n);
        alist.resize(n);
        for (vector<int> i : edges) {
            alist[i[0]].push_back(i[1]);
        }
        dfs(0);
        return ans;
    }
};
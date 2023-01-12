/* Number of Nodes in the Sub-Tree With the Same Label */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> parent(n, -1);
        for (auto i : edges) {
            if (i[0] == 0) {
                parent[i[1]] = 0;
                continue;
            }
            if (i[1] == 0) {
                parent[i[0]] = 0;
                continue;
            }
            if (parent[i[0]] == -1) {
                parent[i[0]] = i[1];
                continue;
            }
            parent[i[1]] = i[0];
        }
        for (auto i : parent) {
            cout << i << endl;
        }
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            int temp = i;
            while (parent[temp] != -1) {
                temp = parent[temp];
                if (labels[temp] == labels[i]) {
                    ans[temp]++;
                }
            }
        }
        return ans;
    }
};
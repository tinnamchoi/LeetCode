/* Longest Path With Different Adjacent Characters */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int ans = 0;
    vector<int> parent;
    vector<vector<int>> child;
    string s;

    int dfs(int i, int count) {
        int max = 0;
        int max2 = 0;
        if (i == 0 || s[parent[i]] == s[i]) {
            count = 1;
        } else {
            count++;
            if (count > ans) {
                ans = count;
            }
        }
        for (int j : child[i]) {
            int temp = dfs(j, count);
            if (s[j] != s[i]) {
                if (temp >= max) {
                    max2 = max;
                    max = temp;
                } else if (temp > max2) {
                    max2 = temp;
                }
                temp = max + max2 + 1;
                if (temp > ans) {
                    ans = temp;
                }
            }
        }
        return max + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        if (n == 1) {
            return 1;
        }
        this->parent = parent;
        this->s = s;
        child.resize(n);
        for (int i = 1; i < n; i++) {
            child[parent[i]].push_back(i);
        }
        dfs(0, 0);
        return ans;
    }
};
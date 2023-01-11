/* Minimum Time to Collect All Apples in a Tree */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> parent(n, 0);
        for (auto i : edges) {
            parent[i[1]] = i[0];
        }
        vector<bool> collected(n, false);
        for (auto i = 0; i < n; i++) {
            if (hasApple[i] == false) {
                continue;
            }
            collected[i] = true;
            int temp = parent[i];
            while (temp != 0) {
                collected[temp] = true;
                temp = parent[temp];
            }
        }
        int count = 0;
        for (bool i : collected) {
            if (i == false) {
                continue;
            }
            count++;
        }
        return count * 2;
    }
};
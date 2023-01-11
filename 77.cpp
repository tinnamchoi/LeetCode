/* Combinations */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                out.push_back({i});
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                out.push_back({i, j});
            }
        }
        return out;
    }
};
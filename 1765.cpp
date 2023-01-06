/* Map of Highest Peak */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> height = isWater;
        int m = height.size();
        int n = height[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (height[i][j] == 0) {
                    height[i][j] = 1;
                } else {
                    height[i][j] = 0;
                }
            }
        }
        bool changed = true;
        int max = 0;
        while (changed) {
            changed = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int temp = height[i][j];
                    if ((temp != 0 || temp > max) && (i == 0 || height[i - 1][j] >= temp) && (i + 1 == m || height[i+1][j] >= temp) && (j == 0 || height[i][j - 1] >= temp) && (j + 1 == n || height[i][j + 1] >= temp)) {
                        height[i][j]++;
                        changed = true;
                    }
                }
            }
            max++;
        }

        return height;
    }
};
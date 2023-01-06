/* Map of Highest Peak */

#include <bits/stdc++.h>

using namespace std;

/* Submission (duplicate) */

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> height = isWater;
        vector<vector<int>> waters;
        int m = height.size();
        int n = height[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (height[i][j] == 1) {
                    waters.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int min = INT_MAX;
                if (isWater[i][j] == 1) {
                    min = 0;
                } else if ((i != 0 && isWater[i - 1][j]) || (i + 1 != m && isWater[i + 1][j]) || (j != 0 && isWater[i][j - 1]) || (j + 1 != m && isWater[i][j + 1])) {
                    min = 1;
                } else {
                    for (auto k : waters) {
                        int dist = abs(k[0] - i) + abs(k[1] - j);
                        if (dist < min) {
                            min = dist;
                        }
                    }
                }
                height[i][j] = min;
            }
        }
        return height;
    }
};
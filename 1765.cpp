/* Map of Highest Peak */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

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
                for (auto k : waters) {
                    if (min == 0) {
                        break;
                    }
                    int dist = abs(k[0] - i) + abs(k[1] - j);
                    if (dist < min) {
                        min = dist;
                    }
                }
                height[i][j] = min;
            }
        }
        return height;
    }
};
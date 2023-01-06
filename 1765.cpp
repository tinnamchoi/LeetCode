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
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                } else {
                    int min;
                    for (int k = 1; k <= max(m, n); k++) {
                        for (int l = 0; l <= k; l++) {
                            if (i - (k - l) >= 0) {
                                if (j - l >= 0) {
                                    if (isWater[i - (k - l)][j - l] == 1) {
                                        min = k;
                                        goto found;
                                    }
                                }
                                if (j + l < n) {
                                    if (isWater[i - (k - l)][j + l] == 1) {
                                        min = k;
                                        goto found;
                                    }
                                }
                            }
                            if (i + (k - l) < m) {
                                if (j - l >= 0) {
                                    if (isWater[i + (k - l)][j - l] == 1) {
                                        min = k;
                                        goto found;
                                    }
                                }
                                if (j + l < n) {
                                    if (isWater[i + (k - l)][j + l] == 1) {
                                        min = k;
                                        goto found;
                                    }
                                }
                            }
                        }
                    }
                    found:
                    height[i][j] = min;
                }
            }
        }
        return height;
    }
};
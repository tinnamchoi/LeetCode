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
        while (changed) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << height[i][j] << " ";
                }
                cout << endl;
            }
            changed = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int temp = height[i][j];
                    if (temp != 0) {
                        if (i == 0 || height[i - 1][j] == temp) {
                            if (i + 1 == m || height[i+1][j] == temp) {
                                if (j == 0 || height[i][j - 1] == temp) {
                                    if (j + 1 == n || height[i][j + 1] == temp) {
                                        height[i][j]++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return height;
    }
};
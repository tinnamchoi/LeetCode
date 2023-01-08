/* Max Points on a Line */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1 || n == 2) {
            return n;
        }
        double dpoints[n][n];
        for (int i = 0; i < n; i++) {
            dpoints[i][0] = (double)points[i][0];
            dpoints[i][1] = (double)points[i][1];
        }
        map<string, int> map1;
        map<int, int> map2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string key;
                if (dpoints[i][0] == dpoints[j][0]) {
                    if (map2.find(dpoints[i][0]) == map2.end()) {
                        map2[points[i][0]] = 1;
                    } else {
                        map2[points[i][0]]++;
                    }
                } else {
                    double temp = (dpoints[i][1] - dpoints[j][1]) / (dpoints[i][0] - dpoints[j][0]);
                    double zero = temp * (0 - dpoints[i][0]) + dpoints[i][1];
                    double ones = temp * (1 - dpoints[i][0]) + dpoints[i][1];
                    key = to_string(zero) + to_string(ones);
                    if (map1.find(key) == map1.end()) {
                        map1[key] = 1;
                    } else {
                        map1[key]++;
                    }
                }
            }
        }
        int max = 0;
        for (auto i : map1) {
            if (i.second > max) {
                max = i.second;
            }
        }
        for (auto i : map2) {
            if (i.second > max) {
                max = i.second;
            }
        }
        cout << "max: " << max << "\n";
        if (max == 1 || max == 2) {
            return max + 1;
        }
        for (int i = 3; i <= max; i++) {
            if (i * (i - 1) == 2 * max) {
                return i;
            }
        }
        return INT_MAX;
    }
};
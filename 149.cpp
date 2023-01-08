/* Max Points on a Line */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

int fact(int num) {
    int temp = 1;
    for (int i = 1; i <= num; i++) {
        temp *= i;
    }
    return temp;
}

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
        map<pair<double,double>, int> map;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pair<double,double> key;
                if (dpoints[i][0] == dpoints[j][0]) {
                    key = make_pair(0, DBL_MAX - dpoints[i][0]);
                } else {
                    double temp = (dpoints[i][1] - dpoints[j][1]) / (dpoints[i][0] - dpoints[j][0]);
                    double zero = temp * (0 - dpoints[i][0]) + dpoints[i][1];
                    double ones = temp * (1 - dpoints[i][0]) + dpoints[i][1];
                    key = make_pair(zero, ones);
                }
                if (map.find(key) == map.end()) {
                    map[key] = 1;
                } else {
                    map[key]++;
                }
            }
        }
        int max = 0;
        for (auto i : map) {
            cout << i.first.first << "," << i.first.second << ": " << i.second << "\n";
            if (i.second > max) {
                max = i.second;
            }
        }
        if (max == 1 || max == 2) {
            return max;
        }
        for (int i = 3; i <= max; i++) {
            int coef = fact(i) / (2 * fact(i - 2));
            if (coef == max) {
                return i;
            }
        }
        return INT_MAX;
    }
};
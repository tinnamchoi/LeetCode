/* Minimum Rounds to Complete All Tasks */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1;
        int temp = 0;
        for (int i = 1; i < points.size(); i++) {
            temp++;
            if (points[i][0] > points[i-temp][1]) {
                temp = 0;
                count++;
            }
        }
        return count;
    }
};
/* Minimum Rounds to Complete All Tasks */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0;
        int popped = 0;

        vector<int> balloons(1, 0);
        for (int i = 0; i < points.size(); i++) {
            for (int j = points[i][0]; j <= points[i][1]; j++) {
                if (j >= balloons.size()) {
                    balloons.resize(j+1, 0);
                }
                balloons[j]++;
            }
        }

        while (popped < points.size()) {
            int index = distance(balloons.begin(),max_element(balloons.begin(), balloons.end()));
            count++;
            for (int i = 0; i < points.size(); i++) {
                if (index >= points[i][0] && index <= points[i][1]) {
                    for (int j = points[i][0]; j <= points[i][1]; j++) {
                        balloons[j]--;
                    }
                    popped++;
                }
            }
        }
        return count;
    }
};
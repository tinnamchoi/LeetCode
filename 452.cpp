/* Minimum Rounds to Complete All Tasks */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0;
        int popped = 0;

        if (points.size() == 1) {
            return 1;
        }

        vector<int> balloons;
        vector<int> balloons2;
        for (int i = 0; i < points.size(); i++) {
            for (int j = points[i][0]; j <= points[i][1]; j++) {
                if (j < 0) {
                    j *= -1;
                    if (j >= balloons2.size()) {
                        balloons2.resize(j+1, 0);
                    }
                    balloons2[j]++;
                    continue;
                }
                if (j >= balloons.size()) {
                    balloons.resize(j+1, 0);
                }
                balloons[j]++;
            }
        }

        vector<int> balloons3;

        for (int i = 0; i < balloons2.size(); i++) {
            balloons3.push_back(balloons2[i]);
        }
        for (int i = 0; i < balloons.size(); i++) {
            balloons3.push_back(balloons[i]);
        }

        balloons = balloons3;

        int offset = balloons2.size();

        while (popped < points.size()) {
            int index = distance(balloons.begin(),max_element(balloons.begin(), balloons.end()));
            count++;
            for (int i = 0; i < points.size(); i++) {
                if (index - offset >= points[i][0] && index - offset <= points[i][1]) {
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
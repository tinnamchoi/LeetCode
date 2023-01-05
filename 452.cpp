/* Minimum Rounds to Complete All Tasks */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1) {
            return 1;
        }

        map<int, int> m;
        for (int i = 0; i < points.size(); i++) {
            for (int j = points[i][0]; j <= points[i][1]; j++) {
                if (m.find(j) == m.end()) {
                    m[j] = 1;
                } else {
                    m[j]++;
                }
            }
        }

        int count = 0;
        int popped = 0;
        while (popped != points.size()) {
            count++;
            int maxindex;
            int maxvalue = 0;
            for (auto i : m) {
                cout << i.first << " " << i.second << endl;
                if (maxvalue < i.second) {
                    maxindex = i.first;
                    maxvalue = i.second;
                }
            }
            maxindex--;
            for (int i = 0; i < points.size(); i++) {
                if (points[i][0] <= maxindex && points[i][1] >= maxindex) {
                    popped++;
                    for (int j = points[i][0]; j <= points[i][1]; j++) {
                        m[j]--;
                    }
                    points.erase(points.begin() + i);
                }
            }
        }

        return count;
    }
};
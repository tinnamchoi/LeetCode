/* Minimum Rounds to Complete All Tasks */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> map;
        for (int i = 0; i < tasks.size(); i++) {
            if (map.find(tasks[i]) == map.end()) {
                map[tasks[i]] = 1;
            } else {
                map[tasks[i]]++;
            }
        }
        int count = 0;
        for (auto const& x : map) {
            if (x.second == 1) {
                return -1;
            }
            if (x.second % 3 == 1 || x.second % 3 == 2) {
                count += x.second / 3 + 1;
                continue;
            }
            count += x.second / 3;
        }
        return count;
    }
};
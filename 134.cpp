/* Gas Station */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int diff = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            int temp = gas[i] - cost[i];
            diff += temp;
            v[i] = temp;
        }
        if (diff < 0) {
            return -1;
        }
        for (int i = 0; i < n; i++) {
            if (v[i] < 0) {
                continue;
            }
            int tank = 0;
            for (int j = i; j < n; j++) {
                tank += v[j];
                if (tank < 0) {
                    goto fail;
                }
            }
            for (int j = 0; j < i; j++) {
                tank += v[j];
                if (tank < 0) {
                    goto fail;
                }
            }
            return i;
            fail:
            continue;
        }
        return -1;
    }
};
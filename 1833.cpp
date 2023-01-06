/* Maximum Ice Cream Bars */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++) {
            if (coins < 0) {
                return i - 1;
            }
            if (coins == 0) {
                return i;
            }
            coins -= costs[i];
        }
        return costs.size();
    }
};
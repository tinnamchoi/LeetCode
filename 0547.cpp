/* Number of Provinces */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] != 1) {
                    continue;
                }
                if (parent[i] == parent[j]) {
                    continue;
                }
                parent[j] = parent[i];
            }
        }
        vector<int> temp;
        int count = 0;
        for (int i : parent) {
            cout << i << endl;
            if (temp.size() == 0) {
                cout << "special pushing " << i << endl;
                temp.push_back(i);
                count++;
                continue;
            }
            bool exists = false;
            for (int j : temp) {
                if (i == j) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                cout << "pushing " << i << endl;
                temp.push_back(i);
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        if (n == 1) {
            return 1;
        }

        // map to store list of same vals
        unordered_map<int, vector<int>> valnodes(n);
        for (int i = 0; i < n; i++) {
            valnodes[vals[i]].push_back(i);
        }

        // adjacency list
        vector<vector<int>> alist(n);
        for (vector<int> i : edges) {
            alist[i[0]].push_back(i[1]);
            alist[i[1]].push_back(i[0]);
        }

        // debug
        cout << "map" << endl;
        for (pair<int, vector<int>> i : valnodes) {
            cout << i.first << ": ";
            for (int j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << "alist" << endl;
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            for (int j : alist[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;

        // main logic
        int count = 0;
        for (auto i : valnodes) {
            int m = i.second.size();
            int val = i.first;
            for (int k = 0; k < m; k++) {
                int kval = i.second[k];
                // BFS
                queue<int> q;
                vector<bool> visited(n, false);
                q.push(kval);
                while (!q.empty()) {
                    int current = q.front();
                    q.pop();
                    visited[current] = true;
                    for (int j : alist[current]) {
                        if (!visited[j] && vals[j] <= val) {
                            q.push(j);
                        }
                    }

                }
                for (int j = k; j < m; j++) {
                    if (visited[i.second[j]]) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
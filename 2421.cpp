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

        // main logic
        int count = 0;
        for (auto i : valnodes) {
            for (int j : i.second) {
                int m = i.second.size();
                int val = vals[j];
                for (int k = j; k < m; k++) {
                    vector<bool> visited(n, false);
                    queue<int> nodes;
                    nodes.push(k);
                    int current;
                    int prev = -1;
                    while (!nodes.empty()) {
                        current = nodes.front();
                        nodes.pop();
                        for (int l : alist[current]) {
                            if (l == k) {
                                count++;
                                goto found;
                            }
                            if (l != prev && vals[l] <= val) {
                                nodes.push(l);
                            }
                        }
                    }
                    found:;
                }
            }
        }
        return count + n - 1;
    }
};
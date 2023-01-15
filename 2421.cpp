class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {      // O(N^2 * (N + E))
        int n = vals.size();

        if (n == 1) {
            return 1;
        }

        // map to store list of same vals       O(N)
        unordered_map<int, vector<int>> valnodes(n);
        for (int i = 0; i < n; i++) {
            valnodes[vals[i]].push_back(i);
        }

        // adjacency list       O(E)
        vector<vector<int>> alist(n);
        for (vector<int> i : edges) {
            alist[i[0]].push_back(i[1]);
            alist[i[1]].push_back(i[0]);
        }

        // main logic
        int count = 0;
        for (auto i : valnodes) {       // O(N)
            int m = i.second.size();
            int val = i.first;
            for (int k = 0; k < m; k++) {       // O(N)
                int kval = i.second[k];
                // BFS      O(N + E)
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
                for (int j = k; j < m; j++) {       // O(N)
                    if (visited[i.second[j]]) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
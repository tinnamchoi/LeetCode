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
        for (auto i : valnodes) { // list of nodes with same valued
            cout << "i.first" << i.first << endl;
            int m = i.second.size();
            cout << "m: " << m << endl;
            for (int j = 0; j < m; j++) {
                int jval = i.second[j];
                cout << "jval: " << jval << endl;
                int val = vals[jval];
                for (int k = j; k < m; k++) { // nodes >= self
                    cout << "k: " << k << endl;
                    vector<bool> visited(n, false);
                    queue<int> nodes;
                    nodes.push(k);
                    int current;
                    while (!nodes.empty()) { // BFS
                        current = nodes.front();
                        cout << "current: " << current << endl;
                        if (current == jval) {
                            count++;
                            break;
                        }
                        nodes.pop();
                        visited[current] = true;
                        for (int l : alist[current]) {
                            if (!visited[l] && vals[l] <= val) {
                                nodes.push(l);
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
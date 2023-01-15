class Solution {
public:
    vector<int> uf;

    int find(int index) {
        if (uf[index] == index) {
            return index;
        }
        return find(uf[index]);
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int m = edges.size();

        // map of nodes with same values
        map<int, vector<int>> valnodes;
        for (int i = 0; i < n; i++) {
            valnodes[vals[i]].push_back(i);
        }

        // adjacency list of nodes, smaller nodes only
        vector<vector<int>> alist(n);
        for (vector<int> i : edges) {
            if (i[0] <= i[1]) {
                alist[i[1]].push_back(i[0]);
            }
            if (i[1] <= i[0]) {
                alist[i[0]].push_back(i[1]);
            }
        }

        // union-find
        for (int i = 0; i < n; i++) {
            uf[i] = i;
        }

        int count = 0;
        for (auto i : valnodes) {
            unordered_map<int, int> sets;
            for (auto j : i.second) {
                int min = INT_MAX;
                for (auto k : alist[j]) {
                    int root = find(k);
                    if (vals[root] < vals[min]) {
                        uf[min] = root;
                        min = root;
                    }
                }
                uf[j] = min;
                sets[min]++;
            }
            for (auto j : sets) {
                count += j.second * (j.second - 1) / 2 + j.second;
            }
        }

        return count;
    }
};
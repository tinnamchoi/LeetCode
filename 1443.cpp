class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> parent(n, -1);
        for (auto i : edges) {
            if (parent[i[1]] != -1) {
                parent[i[0]] = i[1];
                continue;
            }
            parent[i[1]] = i[0];
        }
        vector<bool> collected(n, false);
        for (auto i = 1; i < n; i++) {
            if (hasApple[i] == false) {
                continue;
            }
            collected[i] = true;
            int temp = parent[i];
            while (temp != 0 && temp != -1) {
                collected[temp] = true;
                temp = parent[temp];
            }
        }
        int count = 0;
        for (bool i : collected) {
            if (i == false) {
                continue;
            }
            count++;
        }
        return count * 2;
    }
};
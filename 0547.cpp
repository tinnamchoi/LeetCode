int find(int n, vector<int>& parent) {
    while (parent[n] != n) {
        n = parent[n];
    }
    return n;
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    int iroot = find(i, parent);
                    int jroot = find(j, parent);
                    if (iroot != jroot) {
                        parent[jroot] = iroot;
                    }
                }
            }
        }
        vector<int> roots;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i, parent);
            cout << root << endl;
            bool exists = false;
            for (int j : roots) {
                cout << "root: " << root << ", j: " << j << endl;
                if (root == j) {
                    exists = true;
                    break;
                }
            }
            if (exists == false) {
                count++;
                roots.push_back(root);
            }
        }
        return count;
    }
};
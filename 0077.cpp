class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        if (k == 1) {
            for (int i = 1; i <= n; i++) { // O(N)
                out.push_back({i});
            }
            return out;
        }
        vector<vector<int>> in = combine(n, k - 1);
        for (auto i : in) { //O(N)
            for (int j = i.back() + 1; j <= n; j++) { // O(N)
                vector<int> temp = i;
                temp.push_back(j);
                out.push_back(temp);
            }
        }
        return out;
    }
};
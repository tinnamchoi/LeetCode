class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = INT_MAX;
        for (string & s : strs) {
            n = min(n, (int)s.size());
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char cur = strs[0][i];
            bool bad = false;
            for (string & s : strs) {
                if (s[i] != cur) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                return strs[0].substr(0, ans);
            } else {
                ans++;
            }
        }
        return strs[0].substr(0, n);
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_set<char> exists;
        int ans = 0;

        int l = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, i - l);
            if (exists.find(s[i]) != exists.end()) {
                while (s[l] != s[i]) {
                    exists.erase(s[l]);
                    l++;
                }
                exists.erase(s[l]);
                l++;
            }
            exists.insert(s[i]);
        }

        return ans;
    }
};
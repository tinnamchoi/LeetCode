class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans_index = 0;
        int ans_size = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; i - j >= 0 && i + j < n; j++) {
                if (s[i - j] == s[i + j]) continue;
                if (ans_size < j * 2 - 1) {
                    ans_index = i - j;
                    ans_size = j * 2 - 1;
                }
                break;
            }
            if (s[i - 1] == s[i]) {
                for (int j = 0; i - j >= 0 && i + j < n; j++) {
                    if (s[i - 1 - j] == s[i + j]) continue;
                    if (ans_size < j * 2) {
                        ans_index = i - j;
                        ans_size = j * 2;
                    }
                    break;
                }
            }
        }
        return s.substr(ans_index, ans_size);
    }
};
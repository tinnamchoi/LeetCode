class Solution {
public:
    string longestPalindrome(string s) {
        cout << s << endl;
        int n = s.size();
        int ans_index = 0;
        int ans_size = 1;
        for (int i = 1; i < n; i++) {
            {
                int size = -1;
                for (int j = 0; i - j >= 0 && i + j < n; j++) {
                    if (s[i - j] == s[i + j]) {
                        size = j;
                        continue;
                    }
                    if (ans_size < j * 2 - 1) {
                        ans_index = i - j;
                        ans_size = j * 2 - 1;
                    }
                    size = -1;
                    break;
                }
                size++;
                if (size && ans_size < size * 2 - 1) {
                    ans_index = i - size + 1;
                    ans_size = size * 2 - 1;
                }
            }
            if (s[i - 1] == s[i]) {
                int size = -1;
                for (int j = 0; i - 1 - j >= 0 && i + j < n; j++) {
                    if (s[i - 1 - j] == s[i + j]) {
                        size = j;
                        continue;
                    }
                    if (ans_size < j * 2) {
                        ans_index = i - j;
                        ans_size = j * 2;
                    }
                    size = -1;
                    break;
                }
                size++;
                if (size && ans_size < size * 2) {
                    ans_index = i - size;
                    ans_size = size * 2;
                }
            }
        }
        return s.substr(ans_index, ans_size);
    }
};
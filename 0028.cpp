class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0; 
        int n = haystack.size();
        int m = needle.size();
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (haystack[i] == needle[0]) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < m; i++) {
                if (haystack[cur + i] != needle[i]) {
                    break;
                }
                if (i == m - 1) {
                    return cur;
                }
            }
        }

        return -1;
    }
};
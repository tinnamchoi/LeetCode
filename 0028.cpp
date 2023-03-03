class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0; 
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i < n; i++) {
            if (haystack[i] == needle[index]) {
                index++;
            } else {
                index = 0;
            }
            if (index == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};
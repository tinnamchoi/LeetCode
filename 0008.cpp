class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        bool reading = false;
        bool neg = false;
        long ans = 0;
        for (char & c : s) {
            // ignore leading whitespace
            if (c == ' ' && !reading) {
                continue;
            }
            if (c == '-' || c == '+' && !reading) {
                neg = c == '-';
                continue;
            }
            if (c >= '0' && c <= '9') {
                ans *= 10;
                ans += c - '0';
                if (neg && -1 * ans < INT_MIN) {
                    return INT_MIN;
                }
                if (!neg && ans > INT_MAX) {
                    return INT_MAX;
                }
                continue;
            }
            if (reading) {
                break;
            }
        } 
        return (neg ? -1 : 1) * ans;
    }
};
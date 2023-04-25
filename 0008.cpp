class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        bool reading = false;
        bool neg = false;
        int ans = 0;
        for (char & c : s) {
            // ignore leading whitespace
            if (c == ' ' && !reading) {
                continue;
            }
            if ((c == '-' || c == '+') && !reading) {
                neg = c == '-';
                reading = true;
                continue;
            }
            if (c >= '0' && c <= '9') {
                reading = true;
                if (ans != 0 && INT_MAX / ans < 10) {
                    return neg ? INT_MIN : INT_MAX;
                }
                ans *= 10;
                ans += c - '0';
                continue;
            }
            break;
        } 
        return (neg ? -1 : 1) * ans;
    }
};
class Solution {
public:
    int reverse(int x) {
        if (x < 0) return -1 * reverse(-1 * x);

        long ans;
        while (x) {
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }

        return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
    }
};
class Solution {
private:
    string s;
    string p;
    int ns;
    int np;

    vector<vector<unordered_map<char, bool>>> dp;

    bool IM(int is, int ip, char prefix) {
        bool ans;
        if (dp[is][ip].find(prefix) != dp[is][ip].end()) {
            ans =  dp[is][ip][prefix];
        } else if (is == ns && ip == np || (p[ip] == '*' && IM(is, ip + 1, 0)) || (ip + 1 < np && p[ip + 1] == '*' && IM(is, ip + 2, 0))) {
            ans = true;
        } else if (is == ns) {
            ans = false;
        } else if (prefix == s[is] || prefix == '.') {
            ans = IM(is + 1, ip, prefix) || IM(is, ip, 0);
        } else if (p[ip] == '*') {
            ans = IM(is, ip + 1, p[ip - 1]);
        } else if (p[ip] == '.') {
            ans = IM(is + 1, ip + 1, 0);
        } else {
            ans = (s[is] == p[ip] && IM(is + 1, ip + 1, 0)) || (ip + 1 < np && p[ip + 1] == '*' && IM(is, ip + 1, 0));
        }
        dp[is][ip][prefix] = ans;
        return ans;
    }
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;

        ns = s.size();
        np = p.size();

        dp = vector<vector<unordered_map<char, bool>>> (ns + 1, vector<unordered_map<char, bool>> (np + 1, unordered_map<char, bool> ()));

        return IM(0, 0, 0);
    }
};
class Solution {
private:
    string s;
    string p;
    int ns;
    int np;

    bool IM(int is, char prefix, int ip) {
        if (is == ns && ip == np || (p[ip] == '*' && IM(is, 0, ip + 1)) || (ip + 1 < np && p[ip + 1] == '*' && IM(is, 0, ip + 2))) {
            return true;
        }
        if (is == ns) {
            return false;
        }
        if (prefix == s[is] || prefix == '.') {
            return IM(is + 1, prefix, ip) || IM(is, 0, ip);
        }
        if (p[ip] == '*') {
            return IM(is, p[ip - 1], ip + 1);
        }
        if (p[ip] == '.') {
            return IM(is + 1, 0, ip + 1);
        }
        return (s[is] == p[ip] && IM(is + 1, 0, ip + 1)) || (ip + 1 < np && p[ip + 1] == '*' && IM(is, 0, ip + 1));
    }
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;

        ns = s.size();
        np = p.size();

        return IM(0, 0, 0);
    }
};
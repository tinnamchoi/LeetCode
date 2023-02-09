class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'I':
                    if (i + 1 < n) {
                        switch (s[i + 1]) {
                            case 'V':
                                ans += 4 - 1;
                                i++;
                                break;
                            case 'X':
                                ans += 9 - 1;
                                i++;
                                break;
                        }
                    }
                    ans += 1;
                    break;
                case 'V':
                    ans += 5;
                    break;
                case 'X':
                    if (i + 1 < n) {
                        switch (s[i + 1]) {
                            case 'L':
                                ans += 40 - 10;
                                i++;
                                break;
                            case 'C':
                                ans += 90 - 10;
                                i++;
                                break;
                        }
                    }
                    ans += 10;
                    break;
                case 'L':
                    ans += 50;
                    break;
                case 'C':
                    if (i + 1 < n) {
                        switch (s[i + 1]) {
                            case 'D':
                                ans += 400 - 100;
                                i++;
                                break;
                            case 'M':
                                ans += 900 - 100;
                                i++;
                                break;
                        }
                    }
                    ans += 100;
                    break;
                case 'D':
                    ans += 500;
                    break;
                case 'M':
                    ans += 1000;
                    break;
            }
        }
        return ans;
    }
};
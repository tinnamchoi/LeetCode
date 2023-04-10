class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            cout << c << endl;
            switch (c) {
                case ')':
                    if (stk.top() == '(') {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (stk.top() == '{') {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (stk.top() == '[') {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    stk.push(c);
                    break;
            }
        }
        return true;
    }
};
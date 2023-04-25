class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allupper = true;
        bool hasupper = false;
        if (isupper(word[0]) == 0) { // if is lower
            allupper = false;
        }
        for (int i = 1; i < word.length(); i++) {
            if (isupper(word[i]) != 0) { // if is upper
                hasupper = true;
                if (allupper == false) {
                    return false;
                }
            } else { // is lower
                if (i >= 2 && hasupper == true) {
                    return false;
                }
                allupper = false;
            }
        }
        return true;
    }
};
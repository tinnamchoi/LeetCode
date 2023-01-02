/* Detect Capital */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allupper = true;
        if (isupper(word[0]) == 0) { // if is lower
            allupper = false;
        }
        for (int i = 1; i < word.length(); i++) {
            if (isupper(word[i]) != 0) { // if is upper
                if (allupper == false) {
                    return false;
                }
            } else {
                allupper = false;
            }
        }
        return true;
    }
};
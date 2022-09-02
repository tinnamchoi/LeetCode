class Solution {
 public:
  bool isPalindrome(int x) {
    for (int i = 0; i < to_string(x).size() / 2; i++) {
      if (to_string(x)[i] != to_string(x)[to_string(x).size() - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};
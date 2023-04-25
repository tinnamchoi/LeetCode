class Solution {
public:
    string intToRoman(int num) {
        vector<string> di = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> te = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> hu = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> th = {"", "M", "MM", "MMM"};

        return th[num % 10000 / 1000] + hu[num % 1000 / 100] + te[num % 100 / 10] + di[num % 10];        
    }
};
class Solution {
public:
    string intToRoman(int num) {
        string di[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string te[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hu[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string th[] = {"", "M", "MM", "MMM"};

        return th[num % 10000 / 1000] + hu[num % 1000 / 100] + te[num % 100 / 10] + di[num % 10];        
    }
};
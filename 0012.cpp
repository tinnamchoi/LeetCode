class Solution {
public:
    string intToRoman(int num) {
        int digit = num % 10;
        int ten = num % 100 / 10;
        int hundred = num % 1000 / 100;
        int thousand = num % 10000 / 1000;

        string ans;

        switch (thousand) {
            case 1:
                ans += "M";
                break;
            case 2:
                ans += "MM";
                break;
            case 3:
                ans += "MMM";
                break;
        }
        switch (hundred) {
            case 1:
                ans += "C";
                break;
            case 2:
                ans += "CC";
                break;
            case 3:
                ans += "CCC";
                break;
            case 4:
                ans += "CD";
                break;
            case 5:
                ans += "D";
                break;
            case 6:
                ans += "DC";
                break;
            case 7:
                ans += "DCC";
                break;
            case 8:
                ans += "DCCC";
                break;
            case 9:
                ans += "CM";
                break;
        }
        switch (ten) {
            case 1:
                ans += "X";
                break;
            case 2:
                ans += "XX";
                break;
            case 3:
                ans += "XXX";
                break;
            case 4:
                ans += "XL";
                break;
            case 5:
                ans += "L";
                break;
            case 6:
                ans += "LX";
                break;
            case 7:
                ans += "LXX";
                break;
            case 8:
                ans += "LXXX";
                break;
            case 9:
                ans += "XC";
                break;
        }
        switch (digit) {
            case 1:
                ans += "I";
                break;
            case 2:
                ans += "II";
                break;
            case 3:
                ans += "III";
                break;
            case 4:
                ans += "IV";
                break;
            case 5:
                ans += "V";
                break;
            case 6:
                ans += "VI";
                break;
            case 7:
                ans += "VII";
                break;
            case 8:
                ans += "VIII";
                break;
            case 9:
                ans += "IX";
                break;
        }

        return ans;
    }
};
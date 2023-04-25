class Solution {
public:
    string intToRoman(int num) {
        int digit = num % 10;
        int ten = num % 100 / 10;
        int hundred = num % 1000 / 100;
        int thousand = num % 10000 / 1000;

        string ans;

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
                ans += "VI";
                break;
            case 5:
                ans += "V";
                break;
            case 6:
                ans += "IV";
                break;
            case 7:
                break;
                ans += "IIV";
                break;
            case 8:
                ans += "IIIV";
                break;
            case 9:
                ans += "XI";
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
                ans += "LX";
                break;
            case 5:
                ans += "L";
                break;
            case 6:
                ans += "XL";
                break;
            case 7:
                ans += "XXL";
                break;
            case 8:
                ans += "XXXL";
                break;
            case 9:
                ans += "CX";
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
                break;
                ans += "CCC";
                break;
            case 4:
                ans += "DC";
                break;
            case 5:
                ans += "D";
                break;
            case 6:
                ans += "CD";
                break;
            case 7:
                ans += "CCD";
                break;
            case 8:
                ans += "CCCD";
                break;
            case 9:
                ans += "MC";
                break;
        }
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
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
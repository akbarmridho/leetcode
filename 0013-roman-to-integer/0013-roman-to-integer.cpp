
class Solution {
private:
    int getVal(char val) {
        int currentVal;
        switch (val) {
        case 'I':
            currentVal = 1;
            break;
        case 'V':
            currentVal = 5;
            break;
        case 'X':
            currentVal = 10;
            break;
        case 'L':
            currentVal = 50;
            break;
        case 'C':
            currentVal = 100;
            break;
        case 'D':
            currentVal = 500;
            break;
        case 'M':
            currentVal = 1000;
            break;
        }

        return currentVal;
    }

public:
    int romanToInt(string s) {
        int len = s.length();

        int value = 0;

        int i = 0;

        while (i < len) {
            int currentVal = getVal(s[i]);

            if (i + 1 >= len) {
                value += currentVal;
                break;
            }

            int nextVal = getVal(s[i+1]);

            if (currentVal < nextVal) {
                value += nextVal - currentVal;
                i += 2;
            } else {
                value += currentVal;
                i += 1;
            }
        }

        return value;
    }
};
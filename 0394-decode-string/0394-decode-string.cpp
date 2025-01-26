#include <stack>
#include <iostream>

class Solution {
public:
    string decodeString(string s) {
        stack<char> ss;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                ss.push(s[i]);
                continue;
            }

            // we found close bracket
            string repeat = "";

            while (ss.top() != '[') {
                repeat = ss.top() + repeat;
                ss.pop();
            }

            ss.pop();

            string numstr;

            while (!ss.empty() && ss.top() >= '0' && ss.top() <= '9') {
                numstr = ss.top() + numstr;
                ss.pop();
            }

            int repeatNumber = std::stoi(numstr);

            for (int j = 0; j < repeatNumber; j++) {
                for (int k = 0; k < repeat.length(); k++) {
                    ss.push(repeat[k]);
                }
            }
        }

        int resultLength = ss.size();

        char* result = new char[ss.size() + 1];

        for (int i = resultLength-1; i >= 0; i--) {
            result[i] = ss.top();
            ss.pop();
        }

        result[resultLength] = '\0';

        return string(result);
    }
};
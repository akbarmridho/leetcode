#include <stack>

class Solution {
public:
    string removeStars(string s) {
        stack<char> ss;

        for (char ch: s) {
            if (ch == '*') {
                ss.pop();
            } else {
                ss.push(ch);
            }
        }

        int ressize = ss.size();

        char* result = new char[ressize + 1];

        int i = ressize - 1;

        while (!ss.empty()) {
            result[i--] = ss.top();
            ss.pop();
        }

        result[ressize] = '\0';

        return std::string(result);
    }
};
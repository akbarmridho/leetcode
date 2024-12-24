#include <sstream>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int shortestStrlen = 10000;

        for (const string& str: strs) {
            if (str.length() < shortestStrlen) {
                shortestStrlen = str.length();
            }
        }

        std::stringstream ss;

        int i = 0;

        while (i < shortestStrlen) {
            bool same = true;

            for (const string& str: strs) {
                if (strs[0][i] != str[i]) {
                    same = false;
                    break;
                }
            }

            if (same) {
                ss << strs[0][i];
                i++;
            } else {
                break;
            }
        }

        return ss.str();
    }
};
#include <string>

class Solution {
public:
    int compress(vector<char>& chars) {
        int currentChar = chars[0];
        int count = 1;

        int ptr = 0;

        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] != currentChar) {
                chars[ptr++] = currentChar;
                
                if (count > 1) {
                    std::string cstr = std::to_string(count);

                    for (char ch: cstr) {
                        chars[ptr++] = ch;
                    }
                }

                currentChar = chars[i];
                count = 1;
            } else {
                count++;
            }
        }

        chars[ptr++] = currentChar;
        
        if (count > 1) {
            std::string cstr = std::to_string(count);

            for (char ch: cstr) {
                chars[ptr++] = ch;
            }
        }

        return ptr;
    }
};
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                stack.push(s[i]);
            } else if (s[i] == '}') {
                if (!stack.empty() && stack.top() == '{') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ')') {
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        return stack.empty();
    }
};
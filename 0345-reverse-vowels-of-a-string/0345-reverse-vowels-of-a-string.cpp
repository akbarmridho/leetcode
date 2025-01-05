#include <vector>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o' ||
            ch == 'A' || ch == 'I' || ch == 'U' || ch == 'E' || ch == 'O';
    }

    string reverseVowels(string s) {
        vector<char> vowels;

        for (char ch: s) {
            if (isVowel(ch)) {
                vowels.push_back(ch);
            }
        }

        long long vl = vowels.size();
        long long vi = 0;

        for (long long i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[vl-1-vi];
                vi++;
            }
        }

        return s;
    }
};
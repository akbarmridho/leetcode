class Solution {
public:
    int maxVowels(string s, int k) {
        char count = 0;
        char maxcount = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e'|| s[i] == 'o') {
                count++;
            } else {
                if (count > maxcount) {
                    maxcount = count;

                    if (maxcount >= k) {
                        return k;
                    }
                }
                count = 0;
            }
        }

        if (count > maxcount) {
            maxcount = count;
        }

        if (maxcount < k) {
            return maxcount;
        }

        return k;
    }
};
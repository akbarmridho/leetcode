class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tl = t.length();
        int sl = s.length();

        bool subseq = false;

        int ti = 0;
        int si = 0;

        while (ti < tl && si < sl) {
            if (s[si] == t[ti]) {
                si++;
                ti++;
            } else {
                ti++;
            }
        }

        return si == sl;
    }
};
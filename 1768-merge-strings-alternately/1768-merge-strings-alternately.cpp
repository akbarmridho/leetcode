class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        uint64_t w1l = word1.length();
        uint64_t w2l = word2.length();

        char* results = (char*)malloc((w1l+w2l + 1) * sizeof(char));

        results[w1l+w2l] = '\0';

        uint64_t minlen;

        if (w1l < w2l) {
            minlen = w1l;
        } else {
            minlen = w2l;
        }

        for (uint64_t i = 0; i < minlen; i++) {
            results[2*i] = word1[i];
            results[2*i+1] = word2[i];
        }

        if (w1l != w2l) {
            if (w1l > w2l) {
                for (uint64_t i = 0; i < (w1l-minlen); i++) {
                    results[minlen*2+i] = word1[minlen+i];
                }
            } else {
                for (uint64_t i = 0; i < (w2l-minlen); i++) {
                    results[minlen*2+i] = word2[minlen+i];
                }
            }
        }

        string res = results;

        return res;
    }
};
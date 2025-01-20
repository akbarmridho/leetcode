#include <unordered_map>
#include <bits/stdc++.h>

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }

        unordered_map<char, int> w1map;
        unordered_map<char, int> w2map;
        unordered_set<char> chset;

        for (auto ch: word1) {
            if (w1map.find(ch) == w1map.end()) {
                w1map[ch] = 1;
            } else {
                w1map[ch]++;
            }
            chset.insert(ch);
        }

        for (auto ch: word2) {
            if (w2map.find(ch) == w2map.end()) {
                w2map[ch] = 1;
            } else {
                w2map[ch]++;
            }
            chset.insert(ch);
        }

        // different char set, return false
        if (chset.size() != w1map.size() || chset.size() != w2map.size()) {
            return false;
        }

        // if has same char count for each char, return true

        bool allSame = true;

        for (auto ch: chset) {
            if (w1map[ch] != w2map[ch]) {
                allSame = false;
                break;
            }
        }

        if (allSame) {
            return true;
        }

        // can we say that if we have the same count set for any chars, then
        // it can be constructed into the same word?
        // a bb ccc
        // b cc aaa
        // ops 1 -> b to a
        // a bb ccc
        // a cc bbb

        unordered_map<int, int> w1count;
        unordered_map<int, int> w2count;
        unordered_set<int> countset;

        for (auto kv: w1map) {
            if (w1count.find(kv.second) == w1count.end()) {
                w1count[kv.second] = 1;
            } else {
                w1count[kv.second]++;
            }
            countset.insert(kv.second);
        }

        for (auto kv: w2map) {
            if (w2count.find(kv.second) == w2count.end()) {
                w2count[kv.second] = 1;
            } else {
                w2count[kv.second]++;
            }
            countset.insert(kv.second);
        }

        // different char set, return false
        if (countset.size() != w1count.size() || countset.size() != w2count.size()) {
            return false;
        }

        bool sameCount = true;

        for (auto val: countset) {
            if (w1count[val] != w2count[val]) {
                sameCount = false;
                break;
            }
        }

        return sameCount;
    }
};
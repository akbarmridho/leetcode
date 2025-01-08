#include <unordered_map>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> map;
        std::unordered_set<int> uset;

        for (auto val: arr) {
            if (map.find(val) == map.end()) {
                map[val] = 1;
            } else {
                map[val]++;
            }
        }

        for (auto val: map) {
            if (uset.find(val.second) == uset.end()) {
                uset.insert(val.second);
            } else {
                return false;
            }
        }

        return true;


    }
};
#include <unordered_map>

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;

        for (auto num: nums) {
            if (map.find(num) == map.end()) {
                map[num] = 1;
            } else {
                map[num]++;
            }
        }

        int count = 0;

        for (auto pair: map) {
            if (pair.first * 2 == k) {
                count += (pair.second/2);
            } else {
                if (map.find(k-pair.first) != map.end()) {
                    count += min(pair.second, map.at(k-pair.first));
                    map[pair.first] = 0;
                    map[k-pair.first] = 0;
                }
            }
        }

        return count;
    }
};
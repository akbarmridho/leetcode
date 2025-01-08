#include <algorithm>
#include <vector>
#include <set>

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> s1(nums1.begin(), nums1.end());
        std::set<int> s2(nums2.begin(), nums2.end());

        vector<int> r1(nums1.size()+nums2.size());
        vector<int> r2(nums1.size()+nums2.size());

        auto it1 = std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), r1.begin());
        auto it2 = std::set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), r2.begin());

        r1.resize(it1-r1.begin());
        r2.resize(it2-r2.begin());

        vector<vector<int>> result;

        result.push_back(r1);
        result.push_back(r2);

        return result;
    }
};
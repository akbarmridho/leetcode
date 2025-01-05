class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);

        int maxcandies = 0;

        for (auto candy: candies) {
            if (candy > maxcandies) {
                maxcandies = candy;
            }
        }

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxcandies) {
                result[i] = true;
            }
        }

        return result;
    }
};
#include <limits>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavg = 0;
        double cavg = 0;

        for (int i = 0; i < k; i++) {
            maxavg += (double) nums[i];
            cavg += (double) nums[i];
        }

        for (int i = k; i < nums.size(); i++) {
            cavg += (double) nums[i] - (double) nums[i-k];

            if (cavg > maxavg) {
                maxavg = cavg;
            }
        }

        return maxavg / k;
    }
};
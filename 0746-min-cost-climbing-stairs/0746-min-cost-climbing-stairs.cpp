class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int* dp = new int[cost.size()+1];

        memset(dp, 0, sizeof(int)*(cost.size()+1));

        int n = cost.size();

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = cost[i];

            if (i+2 > n) {
                dp[i] += dp[i+1];
            } else {
                dp[i] += min(dp[i+1], dp[i+2]);
            }
        }

        return min(dp[0], dp[1]);
    }
};
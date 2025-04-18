class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        i_len = len(text1)
        j_len = len(text2)
        dp = [[0]*j_len for _ in range(i_len)]

        # initialization
        for i in range(i_len):
            for j in range(j_len):
                dp[i][0] = 1 if text1[i] == text2[0] else 0

                if i != 0:
                    dp[i][0] += dp[i-1][0]

        for j in range(j_len):
            for i in range(i_len):
                dp[0][j] = 1 if text1[0] == text2[j] else 0

                if j != 0:
                    dp[0][j] += dp[0][j-1]

        for i in range(1, i_len):
            for j in range(1, j_len):
                if text1[i] == text2[j]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])

        print(dp)

        return dp[-1][-1]
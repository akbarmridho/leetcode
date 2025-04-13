from typing import List, Set


class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        result: List[List[int]] = []

        def dfs(nums, k, n, path):
            nonlocal result

            if k < 0 or n < 0:
                return
            if k == 0 and n == 0:
                result.append(path)

            for i in range(len(nums)):
                dfs(nums[i + 1 :], k - 1, n - nums[i], path + [nums[i]])

        dfs([i for i in range(1, 10)], k, n, [])

        return result

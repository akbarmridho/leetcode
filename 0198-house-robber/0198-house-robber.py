from typing import List
from functools import cache


class Solution:
    def rob(self, nums: List[int]) -> int:

        @cache
        def rec(i: int) -> int:
            nonlocal nums

            if i < 0:
                return 0

            return max(nums[i] + rec(i - 2), rec(i - 1))

        return rec(len(nums) - 1)

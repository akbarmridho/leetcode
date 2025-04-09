from typing import List
from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue = deque()
        result = []

        for i in range(len(nums)):
            # remove out of bounds
            while queue and queue[0] <= i - k:
                queue.popleft()

            while queue and nums[queue[-1]] <= nums[i]:
                queue.pop()

            queue.append(i)

            if i >= k - 1:
                result.append(nums[queue[0]])

        return result

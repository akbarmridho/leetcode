import heapq

class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        pq = [(row[0], i, 0) for i, row in enumerate(nums)]
        heapq.heapify(pq)

        ans = -1e9, 1e9

        right = max(row[0] for row in nums)

        while pq:
            left, i, j = heapq.heappop(pq)
            if right - left < ans[1] - ans[0]:
                ans = left, right

            if j + 1 == len(nums[i]):
                return [ans[0], ans[1]]

            val = nums[i][j+1]

            right = max(right, val)
            heapq.heappush(pq, (val, i, j+1))
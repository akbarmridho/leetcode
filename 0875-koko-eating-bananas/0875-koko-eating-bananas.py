from typing import List
import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        min_k = 1
        max_k = max(piles)

        while min_k < max_k:
            k = (min_k + max_k) // 2
            h_need = sum([math.ceil(e / k) for e in piles])

            if h_need <= h:
                # to left
                max_k = k
            elif h_need > h:
                # to right
                min_k = k + 1

        return min_k


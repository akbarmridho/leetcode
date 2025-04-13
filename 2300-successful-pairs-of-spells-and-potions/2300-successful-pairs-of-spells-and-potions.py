from typing import List
import bisect
import math


class Solution:
    def successfulPairs(
        self, spells: List[int], potions: List[int], success: int
    ) -> List[int]:
        potions.sort()
        m = len(potions)

        results = []

        for spell in spells:
            if spell == 0:
                results.append(0)
                continue

            minimum_value = math.ceil(success / spell)

            i = bisect.bisect_left(potions, minimum_value)
            results.append(m - i)

        return results
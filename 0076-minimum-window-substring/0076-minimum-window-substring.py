from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # edge cases
        if s == "" or t == "" or len(t) > len(s):
            return ""

        need = Counter(t)
        required = len(need)

        left = 0
        met_need = 0

        window_counts = {}

        minimum_len = float("inf")
        result = ""

        # move to right
        for right, ch in enumerate(s):
            window_counts[ch] = window_counts.get(ch, 0) + 1

            # check if part of t
            if ch in need and window_counts[ch] == need[ch]:
                met_need += 1

            # shrink
            while left <= right and met_need == required:
                # Update best minimum window
                if (right - left + 1) < minimum_len:
                    minimum_len = right - left + 1
                    result = s[left : right + 1]

                # shrink
                left_ch = s[left]
                window_counts[left_ch] -= 1

                if left_ch in need and window_counts[left_ch] < need[left_ch]:
                    met_need -= 1

                left += 1

        return result

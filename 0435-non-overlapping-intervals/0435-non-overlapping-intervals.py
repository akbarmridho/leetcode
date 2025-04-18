class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = [[e[1], e[0]] for e in intervals]
        intervals.sort()

        count = 0

        last = 0

        for i in range(1, len(intervals)):
            [end, start] = intervals[i]

            if start < intervals[last][0]:
                count += 1
            else:
                last = i

        return count
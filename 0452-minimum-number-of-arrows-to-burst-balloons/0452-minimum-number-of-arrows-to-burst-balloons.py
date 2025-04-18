class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()

        start, end = points[0][0], points[0][1]
        current_overlap_count = 0
        arrow_count = 0

        for i in range(len(points)):
            [cstart, cend] = points[i]
            # if still overlap
            if start <= cstart <= end or start <= cend <= end:
                current_overlap_count += 1
                # update value
                # shrink the start end range
                start = max(start, cstart)
                end = min(end, cend)
            else:
                if current_overlap_count > 0:
                    arrow_count += 1

                start = cstart
                end = cend
                current_overlap_count = 1 # include this element

        if current_overlap_count > 0:
            arrow_count += 1

        return arrow_count
            
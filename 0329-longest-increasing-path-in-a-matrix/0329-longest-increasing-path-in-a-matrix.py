from functools import cache
from typing import List


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        row_n = len(matrix)
        col_n = len(matrix[0])

        @cache
        def dfs(row, col) -> int:
            length = 1

            for r, c in (row + 1, col), (row - 1, col), (row, col + 1), (row, col - 1):
                if (
                    0 <= r < row_n
                    and 0 <= c < col_n
                    and matrix[row][col] < matrix[r][c]
                ):
                    length = max(length, dfs(r, c)+1)

            return length

        return max(dfs(i, j) for i in range(row_n) for j in range(col_n))

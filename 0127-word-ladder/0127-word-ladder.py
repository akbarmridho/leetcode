from typing import List
from collections import deque


def wordDistance(w1: str, w2: str) -> float:
    distance = 0

    for i in range(len(w1)):
        if w1[i] != w2[i]:
            distance += 1

        if distance > 1:
            return float("inf")

    return 1 if distance == 1 else float("inf")


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0

        if beginWord not in wordList:
            wordList.insert(0, beginWord)

        n = len(wordList)

        adj = [[float("inf")] * n for _ in range(len(wordList))]

        for i in range(n):
            for j in range(i + 1, n):
                if i != j:
                    dist = wordDistance(wordList[i], wordList[j])

                    if dist == 1:
                        adj[i][j] = 1
                        adj[j][i] = 1

        # print(wordList)
        # print(adj)

        start_idx = wordList.index(beginWord)
        end_idx = wordList.index(endWord)

        queue = deque([(start_idx, 1)])

        visited = set([start_idx])

        while len(queue) != 0:
            # print(queue)
            # print(visited)
            current_idx, depth = queue.popleft()

            if current_idx == end_idx:
                return depth

            for neighbour_idx in range(n):
                if (
                    adj[current_idx][neighbour_idx] == 1
                    and neighbour_idx not in visited
                ):
                    visited.add(neighbour_idx)
                    queue.append((neighbour_idx, depth + 1))

        return 0


# Solution().ladderLength("hit", "cog", ["hot", "dot", "tog", "cog"])

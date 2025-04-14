from typing import List
import heapq


class MedianFinder:
    left_arr: List[int]  # max heap
    right_arr: List[int]  # min heap

    def __init__(self):
        self.left_arr = []
        self.right_arr = []

    def addNum(self, num: int) -> None:
        # if len same
        if len(self.left_arr) == len(self.right_arr):
            # if value large than smallest min heap
            if len(self.right_arr) > 0 and num > self.right_arr[0]:
                to_insert = heapq.heappushpop(self.right_arr, num)
                heapq.heappush(self.left_arr, -to_insert)
            else:
                heapq.heappush(self.left_arr, -num)
        else:
            # if value smaller than largest min heap
            if num < -self.left_arr[0]:
                to_insert = -heapq.heappushpop(self.left_arr, -num)
                heapq.heappush(self.right_arr, to_insert)
            else:
                heapq.heappush(self.right_arr, num)

    def findMedian(self) -> float:
        if len(self.left_arr) > len(self.right_arr):
            return -self.left_arr[0]

        return (-self.left_arr[0] + self.right_arr[0]) / 2


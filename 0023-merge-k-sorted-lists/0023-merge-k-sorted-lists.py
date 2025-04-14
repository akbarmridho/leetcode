from typing import List, Optional
import heapq


# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        prioq = []
        node_container = []

        head = None
        current = None

        for linklist in lists:
            curr = linklist

            while curr is not None:
                node_container.append(curr)
                prioq.append((curr.val, len(node_container) - 1))
                curr = curr.next

        heapq.heapify(prioq)

        while len(prioq) != 0:
            node = node_container[heapq.heappop(prioq)[1]]

            if head is None:
                head = node

            if current is None:
                current = node
            else:
                current.next = node
                current = node

        if current is not None:
            current.next = None

        return head

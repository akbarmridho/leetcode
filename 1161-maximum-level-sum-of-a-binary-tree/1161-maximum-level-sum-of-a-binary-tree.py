# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        level = 1
        sum = None

        cqueue = []
        nqueue = []

        if root is not None:
            cqueue.append(root)

        c_level = 1

        while True:
            if len(cqueue) == 0:
                break

            print(f"level {c_level} with queue {cqueue}")

            csum = 0
            
            for node in cqueue:
                if node is not None:
                    csum += node.val
                    if node.left:
                        nqueue.append(node.left)
                    if node.right:
                        nqueue.append(node.right)

            if sum is None or csum > sum:
                level = c_level
                sum = csum

            cqueue = nqueue
            nqueue = []
            c_level += 1

        return level
            
        
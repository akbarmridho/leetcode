
from typing import Optional


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_path = float("-inf")

        def get_max_gain(node: Optional[TreeNode]) -> int:
            nonlocal max_path

            if node is None:
                return 0

            gain_left = max(get_max_gain(node.left), 0)
            gain_right = max(get_max_gain(node.right), 0)

            current_max_path = (
                node.val + gain_left + gain_right
            )  # evaluate values involved with node, left, and right

            max_path = max(max_path, current_max_path)

            return node.val + max(
                gain_left, gain_right
            )  # values for when parent is included

        result = get_max_gain(root)

        return max(max_path, result)

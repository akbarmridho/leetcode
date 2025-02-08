/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function getSuccessor(root: TreeNode) {
    let node = root.right;

    while (node !== null && node.left !== null) {
        node = root.left;
    }

    return node;
}

function deleteNode(root: TreeNode | null, key: number): TreeNode | null {
    if (root === null) {
        return null;
    }

    if (key > root.val) {
        root.right = deleteNode(root.right, key);
    } else if (key < root.val) {
        root.left = deleteNode(root.left, key);
    } else {

        if (root.right === null) {
            return root.left;
        } else if (root.left === null) {
            return root.right;
        } else {
            // both node exist
            const successor = getSuccessor(root);

            root.val = newval;
            root.right = deleteNode(root.right, successor.val);
        }

    }

    return root;
};
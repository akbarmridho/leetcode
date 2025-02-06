/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

function traverse(root, p, q, path, result) {
    if (root === null || (result.q !== null && result.p !== null)) {
        return;
    }

    const currentPath = [...path, root];

    if (root.val === p.val) {
        result.p = [...currentPath];
    }

    if (root.val === q.val) {
        result.q = [...currentPath];
    }

    traverse(root.left, p, q, currentPath, result);
    traverse(root.right, p, q, currentPath, result);
}

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    // get the path of each p, q
    const result = {
        p: null,
        q: null
    };

    traverse(root, p, q, [], result);

    const qset = new Set(result.q);
    const intersection = result.p.filter(e => qset.has(e));

    return intersection[intersection.length - 1];
};
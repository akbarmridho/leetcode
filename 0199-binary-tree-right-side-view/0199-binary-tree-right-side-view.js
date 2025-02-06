/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function(root) {
    let currentQueue = [root];
    let nextQueue = [];
    const result = [];

    while (true) {
        for (const node of currentQueue) {
            if (node === null) continue;

            if (node.left) {
                nextQueue.push(node.left);
            }
            if (node.right) {
                nextQueue.push(node.right);
            }
        }
        
        if (currentQueue.length === 0) {
            break;
        }

        for (let i = currentQueue.length - 1; i >= 0; i--) {
            const node = currentQueue[i];

            if (node !== null) {
                result.push(node.val);
                break;
            }
        }

        currentQueue = nextQueue;
        nextQueue = [];
    }


    return result;
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, int currentMax, int* result) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= currentMax) {
            (*result)++;
            currentMax = root->val;
        }

        traverse(root->left, currentMax, result);
        traverse(root->right, currentMax, result);
    }

    int goodNodes(TreeNode* root) {
        int result = 0;
        traverse(root, -100000000, &result);

        return result;
    }
};
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
    void traverse(TreeNode* root, int targetSum, int* result, vector<int> &sums) {
        if (root == nullptr) {
            return;
        }

        vector<int> newsums = sums;

        for (int i = 0; i < newsums.size(); i++) {
            newsums[i] += root->val;
            if (newsums[i] == targetSum) {
                (*result)++;
            }
        }

        newsums.push_back(root->val);
        if (root->val == targetSum) {
            (*result)++;
        }

        traverse(root->left, targetSum, result, newsums);
        traverse(root->right, targetSum, result, newsums);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;
        vector<int> initial;
        traverse(root, targetSum, &result, initial);
        return result;
    }
};
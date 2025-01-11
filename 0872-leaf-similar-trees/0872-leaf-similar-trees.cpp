#include <vector>

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
private:
    void nextLeafValue(TreeNode* node, vector<int> *result) {
        if (node == nullptr) {
            return;
        }

        // check if leaf
        if (node->left == nullptr && node->right == nullptr) {
            result->push_back(node->val);
            return;
        } 

        if (node->left != nullptr) {
            nextLeafValue(node->left, result);
        }

        if (node->right != nullptr) {
            nextLeafValue(node->right, result);
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> rl1;
        vector<int> rl2;

        nextLeafValue(root1, &rl1);
        nextLeafValue(root2, &rl2);

        if (rl1.size() != rl2.size()) {
            return false;
        }

        for (int i = 0; i < rl1.size(); i++) {
            if (rl1[i] != rl2[i]) {
                return false;
            }
        }

        return true;
    }
};
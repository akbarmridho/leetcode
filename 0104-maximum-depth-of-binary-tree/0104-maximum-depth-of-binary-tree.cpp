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
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        vector<TreeNode*>* parent = new vector<TreeNode*>();
        vector<TreeNode*>* children = new vector<TreeNode*>();;

        parent->push_back(root);

        while(!parent->empty()) {
            depth++;
            for (auto p: *parent) {
                if (p->left != nullptr) {
                    children->push_back(p->left);
                }
                if (p->right != nullptr) {
                    children->push_back(p->right);
                }
            }

            vector<TreeNode*>* im = children;
            children = parent;
            parent = im;
            children->clear();
        }

        return depth;
    }
};
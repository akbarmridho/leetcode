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
    int zigZag(TreeNode* node, bool isLeft, int currentHeight) {
        if (node == nullptr) {
            return currentHeight - 1;  // Subtract 1 since we added 1 for a non-existent edge
        }

        if (!isLeft && node->right != nullptr) {
            int result = zigZag(node->right, true, currentHeight+1);

            // try alternate
            if (node->left != nullptr) {
                int alt = zigZag(node->left, true, 0);

                if (alt > result) {
                    result = alt;
                }
            }

            return result;
        } else if (isLeft && node->left != nullptr) {
            int result = zigZag(node->left, false, currentHeight+1);

            // try alternate
            if (node->right != nullptr) {
                int alt = zigZag(node->right, false, 0);

                if (alt > result) {
                    result = alt;
                }
            }

            return result;
        } else if (isLeft && node->left == nullptr) {
            int result = currentHeight;

            // try alternate
            if (node->right != nullptr) {
                int alt = zigZag(node->right, false, 0);

                if (alt > result) {
                    result = alt;
                }
            }

            return result;
        } else if (!isLeft && node->right == nullptr) {
            int result = currentHeight;

            // try alternate
            if (node->left != nullptr) {
                int alt = zigZag(node->left, true, 0);

                if (alt > result) {
                    result = alt;
                }
            }

            return result;
        } 

        cout << "Unreachable code\n";

        return 0;
    }

    int longestZigZag(TreeNode* root) {
        int res1 = zigZag(root, true, 0);
        int res2 = zigZag(root, false, 0);

        if (res1 > res2) {
            return res1;
        }

        return res2;
    }
};
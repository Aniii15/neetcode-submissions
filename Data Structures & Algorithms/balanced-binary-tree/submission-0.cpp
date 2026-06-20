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
    int flag = 1;
    int maxDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int left_h = maxDepth(root->left);
        int right_h = maxDepth(root->right);
        if (abs(left_h - right_h) > 1){
            flag = 0;
        }

        return 1 + max(left_h, right_h);
    }

    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return flag;
    }
};

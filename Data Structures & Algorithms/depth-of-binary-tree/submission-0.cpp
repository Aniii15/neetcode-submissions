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

    // int m = 0;
    // int curr = 0;
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            // curr = 0;
            return 0;
            }

        // curr++;
        // m = max(m,curr);
        // maxDepth(root->left);
        // maxDepth(root->right);
        
        return 1 + max(maxDepth(root->right), maxDepth(root->left));
    }
};

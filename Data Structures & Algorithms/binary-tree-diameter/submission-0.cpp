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
    // 1. Our global spy variable to track the max diameter found anywhere
    int max_diam = 0;

    // 2. We slightly modify your maxDepth function
    int maxDepth(TreeNode* root) {
        // Base case
        if (root == nullptr) {
            return 0;
        }

        // Go get the max depth of the left and right subtrees
        int left_h = maxDepth(root->left);
        int right_h = maxDepth(root->right);

        // THE HIJACK: The diameter passing through THIS specific node is left_h + right_h.
        // Is it bigger than our record? Update the tracker!
        max_diam = max(max_diam, left_h + right_h);

        // THE NORMAL JOB: Tell the parent node above us how tall we are
        return 1 + max(left_h, right_h);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // Run the hijacked depth function.
        // We don't care about the final returned height, we just want it to run.
        maxDepth(root);

        // Return the global record!
        return max_diam;
    }
};

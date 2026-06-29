class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case: We hit the bottom, OR we found one of our targets
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Delegate the search down to the leaves (Post-Order)
        TreeNode* left_result = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_result = lowestCommonAncestor(root->right, p, q);

        // EVALUATION (The Collision)
        // If both sides found something, this current node is the LCA!
        if (left_result != nullptr && right_result != nullptr) {
            return root;
        }

        // Otherwise, pass up whatever we found (if anything)
        return (left_result != nullptr) ? left_result : right_result;
    }
};
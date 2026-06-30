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
    // 1. Declare our Global Spy and a Map for O(1) lookups
    int pre_idx = 0;
    unordered_map<int, int> in_map;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 2. The LeetCode Reset Tax! 
        pre_idx = 0;
        in_map.clear();
        
        // Map the inorder values to their indices
        for (int i = 0; i < inorder.size(); i++) {
            in_map[inorder[i]] = i;
        }
        
        // Launch the recursive builder covering the whole array (0 to size-1)
        return build(preorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int left, int right) {
        // Base Case: If boundaries cross, this subtree is empty.
        if (left > right) return nullptr;

        // PRE-ORDER ACTION (Root): 
        // Grab the value using our spy, then increment the spy for the next call!
        int root_val = preorder[pre_idx++];
        TreeNode* root = new TreeNode(root_val);

        // Find where this root is in the Inorder array
        int mid = in_map[root_val];

        // GO LEFT: We MUST build the left side first, 
        // so our spy tracks the left children in the preorder array perfectly.
        // Left subtree lives between 'left' and 'mid - 1'
        root->left = build(preorder, left, mid - 1);

        // GO RIGHT: By the time this runs, the spy has already processed all left nodes!
        // Right subtree lives between 'mid + 1' and 'right'
        root->right = build(preorder, mid + 1, right);

        return root;
    }
};

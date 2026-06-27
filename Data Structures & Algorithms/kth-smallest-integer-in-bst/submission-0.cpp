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
    int idx = 1;
    int val = 0;

    void inOrder(TreeNode* root, int k){
        if (root == nullptr) return;

        inOrder(root->left, k);
        if(idx == k){
            val = root->val;
        }
        idx++;
        inOrder(root->right, k);
    }


    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);

        return val;
    }
};

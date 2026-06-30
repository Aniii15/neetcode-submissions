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
    int dfs(TreeNode* node, int maxVal){
        if(node == nullptr) return 0;

        int ans = 0;
        if(node->val >= maxVal){
            ans++;
            maxVal = node->val;
        }
        ans += dfs(node->left, maxVal) + dfs(node->right, maxVal);
        return ans;
    }
    int goodNodes(TreeNode* root) {
        int final = dfs(root, root->val);
        return final;
    }
};

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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> result; // Only store the answers!
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // If this is the VERY FIRST node we process on this level, 
                // it MUST be the right-most node (because you push right child first).
                if (i == 0) {
                    result.push_back(curr->val);
                }

                // Your brilliant right-first push order
                if (curr->right != nullptr) q.push(curr->right);
                if (curr->left != nullptr) q.push(curr->left);
            }
        }
        
        return result;
    }
};
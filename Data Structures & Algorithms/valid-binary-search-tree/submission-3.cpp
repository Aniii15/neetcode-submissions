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
    // bool flag = true;
    stack<int> st;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if(!isValidBST(root->left)){
            return false;
        }

        if(st.empty() || st.top() < root->val) {
            st.push(root->val);
        }
        else return false;


        return isValidBST(root->right);
    }

};

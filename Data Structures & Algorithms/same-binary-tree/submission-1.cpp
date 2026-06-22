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
    int nodes = 0;
    int matches = 0;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr){
            if(p != q){
                matches = -1;
                return false;
            }
            return true;
        }
        if(p->val == q->val) {
            matches++;
        }
        nodes++;
        isSameTree(p->left, q->left);
        isSameTree(p->right, q->right);

        return (matches == nodes);
    }
};

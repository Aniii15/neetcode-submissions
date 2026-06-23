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
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> allLevels;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            vector<int> thisLevel;
            int levelSize = q.size();
            while(levelSize--){
                TreeNode* curr = q.front();
                q.pop();

                thisLevel.push_back(curr->val);

                if(curr->right != nullptr) q.push(curr->right);
                if(curr->left != nullptr) q.push(curr->left);

            }
            allLevels.push_back(thisLevel);
        }
        vector<int> result;
        for(int i = 0; i < allLevels.size(); i++){
            result.push_back(allLevels[i][0]);
        }

        return result;
    }
};

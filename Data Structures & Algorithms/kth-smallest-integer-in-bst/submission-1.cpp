class Solution {
public:
    // 1. Declare your Global Spies
    int idx = 1;
    int val = -1; 

    int kthSmallest(TreeNode* root, int k) {
        // 2. The LeetCode Reset Tax
        // You MUST reset them here so Test Case 2 doesn't start with Test Case 1's data.
        idx = 1;
        val = -1;
        
        inOrder(root, k);
        
        return val;
    }

    // Notice: We don't pass idx or val here at all. The function can already see them.
    void inOrder(TreeNode* root, int k) {
        // 3. The Ultimate Kill-Switch
        // If we hit a null node, OR if a previous recursive call already found the answer, 
        // instantly kill this branch and return.
        if (root == nullptr || idx > k) {
            return;
        }

        // Go Left
        inOrder(root->left, k);

        // 4. Another check just in case the left child JUST found it
        // We don't want to process the current node if the left child succeeded.
        if (idx > k) return;

        // Process Current Node
        if (idx == k) {
            val = root->val;
            idx++; // Increment to push idx > k, triggering the kill-switch for all parents!
            return; // Kill this specific frame
        }
        idx++;

        // Go Right
        inOrder(root->right, k);
    }
};


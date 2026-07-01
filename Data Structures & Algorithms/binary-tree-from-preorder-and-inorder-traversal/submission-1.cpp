class Solution {
public:
    // Our O(1) lookup table to avoid the Python .index() penalty
    unordered_map<int, int> in_map;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build the map once
        for (int i = 0; i < inorder.size(); i++) {
            in_map[inorder[i]] = i;
        }
        
        // Launch the helper function covering the full arrays (0 to size-1)
        return build(preorder, 0, preorder.size() - 1, 
                     inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd) {
        
        // Base Case: If our "virtual slices" are empty
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // 1. preorder[0] is the root (using preStart as our virtual 0)
        TreeNode* root = new TreeNode(preorder[preStart]);

        // 2. Find the split point in the inorder array
        int mid = in_map[root->val];

        // 3. Calculate exactly how many elements go to the left side
        int numsLeft = mid - inStart;

        // --- THE TRANSLATION ---
        
        // Python: root.left = build(preorder[1 : mid+1], inorder[:mid])
        // C++:
        // Preorder: skip the root (+1), take exactly 'numsLeft' elements
        // Inorder: take everything from the start up to the element just before 'mid'
        root->left = build(preorder, preStart + 1, preStart + numsLeft, 
                           inorder, inStart, mid - 1);

        // Python: root.right = build(preorder[mid+1 :], inorder[mid+1:])
        // C++: 
        // Preorder: start immediately after the left elements, go to the end
        // Inorder: start immediately after 'mid', go to the end
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, 
                            inorder, mid + 1, inEnd);

        return root;
    }
};
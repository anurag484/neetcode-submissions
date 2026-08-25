class Solution {
public:
    int height(TreeNode* root, int& diameter) {   // <- pass by reference
        if (!root) return 0;

        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);

        // diameter in edges: longest path through this node = lh + rh
        diameter = max(diameter, lh + rh);

        // height in nodes
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};

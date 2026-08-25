class Solution {
public:
    // Function to calculate the height of the tree
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }

    // Function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        // Get the height of the left and right subtrees
        int lh = height(root->left);
        int rh = height(root->right);

        // Diameter passing through the current node
        int diameterThroughRoot = lh + rh;

        // Diameter in the left subtree
        int leftDiameter = diameterOfBinaryTree(root->left);

        // Diameter in the right subtree
        int rightDiameter = diameterOfBinaryTree(root->right);

        // Return the maximum of all three
        return max(diameterThroughRoot, max(leftDiameter, rightDiameter));
    }
};

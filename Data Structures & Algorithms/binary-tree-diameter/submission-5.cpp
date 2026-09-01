class Solution {
public:

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        int currentDiameter = lh + rh;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(currentDiameter,
                   max(leftDiameter, rightDiameter));
    }
};
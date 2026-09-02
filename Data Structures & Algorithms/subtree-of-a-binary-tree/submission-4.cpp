class Solution {
public:

    // Check if two trees are identical
    bool sameTree(TreeNode* p, TreeNode* q) {

        // Both are NULL
        if (p == NULL && q == NULL) {
            return true;
        }

        // One is NULL, other is not
        if (p == NULL || q == NULL) {
            return false;
        }

        // Values must be same
        if (p->val != q->val) {
            return false;
        }

        // Both left and right subtrees must be same
        return sameTree(p->left, q->left) &&
               sameTree(p->right, q->right);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // If root becomes NULL, no subtree can be found
        if (root == NULL) {
            return false;
        }

        // Check if current subtree is identical to subRoot
        if (sameTree(root, subRoot)) {
            return true;
        }

        // Search in left and right subtrees
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
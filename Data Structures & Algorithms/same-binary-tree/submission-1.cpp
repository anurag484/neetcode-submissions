class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both nodes are NULL
        if (p == NULL && q == NULL) {
            return true;
        }

        // Only one node is NULL
        if (p == NULL || q == NULL) {
            return false;
        }

        // Both exist: compare values and subtrees
        return p->val == q->val &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
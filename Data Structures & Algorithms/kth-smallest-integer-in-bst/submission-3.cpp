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
    void inorder(TreeNode* node, int k, int& count, int& result) {
        if (!node || count >= k) return; // Base case: null node or already found Kth smallest

        // Traverse left subtree
        inorder(node->left, k, count, result);

        // Increment counter and check if current node is the Kth smallest
        count++;
        if (count == k) {
            result = node->val;
            return;
        }

        // Traverse right subtree
        inorder(node->right, k, count, result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0; // To track the number of nodes visited
        int result = INT_MIN; // To store the Kth smallest value
        inorder(root, k, count, result);
        return result;
    }
};

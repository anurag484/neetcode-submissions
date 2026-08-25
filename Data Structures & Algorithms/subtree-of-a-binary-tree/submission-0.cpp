class Solution {
public:
    // Helper function to perform preorder traversal and serialize the tree into a string
    string preOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return "null,";
        }
        
        string result = "^" + to_string(node->val) + ",";  // Add a marker and the value
        result += preOrderTraversal(node->left);          // Traverse the left subtree
        result += preOrderTraversal(node->right);         // Traverse the right subtree
        
        return result;
    }

    // Helper function to check if a string is a substring of another string
    bool isSubstring(const string& fullTree, const string& subTree) {
        int n = fullTree.size();
        int m = subTree.size();

        for (int i = 0; i <= n - m; i++) { // Iterate through the main string
            int j = 0;
            while (j < m && fullTree[i + j] == subTree[j]) {
                j++;
            }
            if (j == m) { // Found the substring
                return true;
            }
        }
        return false; // Substring not found
    }

    // Function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Serialize both trees into strings
        string fullTree = preOrderTraversal(root);
        string subTree = preOrderTraversal(subRoot);

        // Use the custom substring function to check for containment
        return isSubstring(fullTree, subTree);
    }
};
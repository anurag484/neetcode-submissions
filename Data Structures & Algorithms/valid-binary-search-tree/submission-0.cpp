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
    bool valid(TreeNode* root,int minVal,int maxVal){
        if(root==NULL){
            return true;
        }
        if(root->val>=maxVal || root->val<=minVal){
            return false;
        }
        return valid(root->left,minVal,root->val) && valid(root->right,root->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,INT_MIN,INT_MAX);
    }
};

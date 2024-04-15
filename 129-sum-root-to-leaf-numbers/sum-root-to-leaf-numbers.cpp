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
    int fun(TreeNode *root,int s)
    {
        if(!root)return 0;
        if(!root->left and !root->right)return (s*10)+root->val;
        return fun(root->left,(s*10)+root->val)+fun(root->right,(s*10)+root->val);
    }
    int sumNumbers(TreeNode* root) {
        return fun(root,0);
    }
};
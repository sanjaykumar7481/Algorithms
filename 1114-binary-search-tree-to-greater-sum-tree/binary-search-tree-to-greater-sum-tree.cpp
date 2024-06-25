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
    void fun(TreeNode *root,int &s)
    {
        if(!root)return;
        fun(root->right,s);
        root->val+=s;
        s=root->val;
        //cout<<root->val<<" ";
        fun(root->left,s);
        // s=root->val;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int s=0;
        fun(root->right,s);
        root->val+=s;
        s=root->val;
        fun(root->left,s);
        return root;
    }
};
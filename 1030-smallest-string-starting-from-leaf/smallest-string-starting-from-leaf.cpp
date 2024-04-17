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
    string res;
    void fun(TreeNode *root,string ans)
    {
        if(!root)return;
        if(!root->left and !root->right)
        {
            ans=char(97+root->val)+ans;
            if(res=="")res=ans;
            if(res>ans)res=ans;
            return;
        }
        fun(root->left,char(97+root->val)+ans);
        fun(root->right,char(97+root->val)+ans);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        fun(root,"");
        return res;
    }
};
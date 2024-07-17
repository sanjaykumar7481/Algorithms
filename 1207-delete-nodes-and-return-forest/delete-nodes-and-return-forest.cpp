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
    bool fun(TreeNode *root,unordered_map<int,int>&mp,vector<TreeNode*>&res)
    {
        if(!root)return false;
        bool left=fun(root->left,mp,res);
        bool right=fun(root->right,mp,res);
        if(left)root->left=NULL;
        if(right)root->right=NULL;
        if(mp.find(root->val)!=mp.end())
        {
            if(root->left)res.push_back(root->left);
            if(root->right)res.push_back(root->right);
            root=NULL;
            return true;
        }
        return false;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int>mp;
        for(auto i:to_delete)mp[i]=0;
        vector<TreeNode*>res;
        bool a=fun(root,mp,res);
        if(!a)res.push_back(root);
        return res;
    }
};
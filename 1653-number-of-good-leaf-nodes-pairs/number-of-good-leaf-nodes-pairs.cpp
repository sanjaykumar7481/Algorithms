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
    int count=0;
    vector<int> fun(TreeNode *root,int dist,int lvl)
    {
        if(!root)return {};
        auto left=fun(root->left,dist,lvl+1);
        auto right=fun(root->right,dist,lvl+1);
        for(auto i:left)
        {
            for(auto j:right)
            {
                if(i+j-(2*lvl)<=dist)count++;
            }
        }
        for(auto i:right)left.push_back(i);
        if(!root->left and !root->right)left.push_back(lvl);
        return left;
    }
    int countPairs(TreeNode* root, int distance) {
        vector<int>mp=fun(root,distance,0);
        return count;
    }
};
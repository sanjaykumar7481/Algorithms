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
    int res=0;
    int fun(TreeNode* root)
    {
        if(!root)return 0;
        int a=fun(root->left);
        int b=fun(root->right);
        if(root->val==0)
        {
            res+=abs(a+b-1);
            return a+b-1;
        }
        if(root->val>1)
        {
            int k=a+b+root->val-1;
            res+=abs(k);
            return k;
        }
        res+=abs(a+b);
        return a+b;
    }
    int distributeCoins(TreeNode* root) {
        int t=fun(root);
        return res;
    }
};
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
    void fun(TreeNode* root,int minn,int maxx,int &ans)
    {
        if(!root)return;
        maxx=max(maxx,root->val);
        minn=min(minn,root->val);
        fun(root->left,minn,maxx,ans);
        fun(root->right,minn,maxx,ans);
        cout<<minn<<" "<<maxx<<"-"<<root->val<<endl;
        ans=max(ans,max(abs(root->val-minn),abs(root->val-maxx)));
        return;
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=-1;
        fun(root,INT_MAX,-1,ans);
        return ans;
    }
};
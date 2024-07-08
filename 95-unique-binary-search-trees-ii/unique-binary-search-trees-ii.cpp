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
    vector<TreeNode*> fun(int st,int end)
    {
        if(st>end)return {NULL};
        vector<TreeNode*>temp;
        for(int i=st;i<=end;i++)
        {
            auto a=fun(st,i-1);
            auto b=fun(i+1,end);
            for(auto x:a)
            {
                for(auto y:b)
                {
                    TreeNode *nn=new TreeNode(i);
                    nn->left=x;
                    nn->right=y;
                    temp.push_back(nn);
                }
            }
        }
        return temp;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return fun(1,n);
    }
};
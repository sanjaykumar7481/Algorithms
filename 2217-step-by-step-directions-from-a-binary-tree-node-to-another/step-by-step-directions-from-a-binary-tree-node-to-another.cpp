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
    TreeNode *LCS=NULL;
    string left,right;
    bool fun(TreeNode *root,int st,int dest)
    {
        if(!root)return false;
        bool a=fun(root->left,st,dest);
        bool b=fun(root->right,st,dest);
        if(!LCS)
        {
            if(root->val==st)
            {
                if(!a)a=true;
                else b=true;
            }
            if(root->val==dest)
            {
                if(!a)a=true;
                else b=true;
            }
            if(a and b)
            {
                LCS=root;
                return false;
            }
            return a or b;
        }
        return false;
    }
    void left_path(TreeNode *root,int st,string &res)
    {
        if(!root)return;
        if(root->val==st)
        {
            left=res;
            return;
        }
        res+="U";
        left_path(root->left,st,res);
        res.pop_back();
        res+="U";
        left_path(root->right,st,res);
        res.pop_back();
    }
    void right_path(TreeNode *root,int st,string &res)
    {
        if(!root)return;
        if(root->val==st)
        {
            right=res;
            return;
        }
        res+="L";
        right_path(root->left,st,res);
        res.pop_back();
        res+="R";
        right_path(root->right,st,res);
        res.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        bool f=fun(root,startValue,destValue);
        string res;
        left_path(LCS,startValue,res);
        right_path(LCS,destValue,res);
        return left+right;
    }
};
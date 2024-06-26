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
    void inorder(TreeNode *root,vector<int>&array)
    {
        if(!root)return;
        inorder(root->left,array);
        array.push_back(root->val);
        inorder(root->right,array);
    }
    TreeNode* Balance(vector<int>&array,int i,int j)
    {
        if(i<=j)
        {
            int m=(i+j)/2;
            TreeNode *newNode=new TreeNode(array[m]);
            newNode->left=Balance(array,i,m-1);
            newNode->right=Balance(array,m+1,j);
            return newNode;
        }
        return NULL;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>array;
        inorder(root,array);
        return Balance(array,0,array.size()-1);
    }
};
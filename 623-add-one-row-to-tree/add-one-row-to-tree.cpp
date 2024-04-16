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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*>q;
        q.push(root);
        if(depth==1)
        {
            TreeNode *parent=root;
            TreeNode *Left=new TreeNode(val);
            // TreeNode *Right=new TreeNode(val);
                    Left->left=parent;
                    // Right->right=parent->right;
                    // parent->left=Left;
            return Left;
                    // parent->right=Right;
        }
        while(!q.empty())
        {
            int size=q.size();
            depth--;
            while(size--)
            {
                auto parent=q.front();
                q.pop();
                if(depth==1)
                {
                    TreeNode *Left=new TreeNode(val);
                    TreeNode *Right=new TreeNode(val);
                    Left->left=parent->left;
                    Right->right=parent->right;
                    parent->left=Left;
                    parent->right=Right;
                }
                else
                { 
                    if(parent->left)q.push(parent->left);
                    if(parent->right)q.push(parent->right);   
                }
            }
            if(depth==1)return root;
        }
        return root;
    }
};
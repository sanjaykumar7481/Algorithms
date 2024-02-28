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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans;
        while(!q.empty())
        {
            int n=q.size();
            bool t=true;
            while(n--)
            {
                auto a=q.front();
                q.pop();
                if(t)
                {
                    ans=a->val;
                    t=false;
                    
                }
                if(a->left)q.push(a->left);
                if(a->right)q.push(a->right);
            }
        }
        return ans;
    }
};
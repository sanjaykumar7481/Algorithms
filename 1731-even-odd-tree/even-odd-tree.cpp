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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int lvl=0;
        while(!q.empty())
        {
            int n=q.size();
            bool odd=false,even=false;
            int pre;
            if(lvl%2==1)
            {
                odd=true;
                pre=INT_MAX;
            }
            else{
                pre=0;
                even=true;
            }
            while(n--)
            {
                auto a=q.front();
                q.pop();
                if(even)
                {
                    if(a->val%2==0)return false;
                    if(pre<a->val)pre=a->val;
                    else{
                        cout<<lvl<<endl;
                        return false;
                    }
                }
                if(odd)
                {
                    if(a->val%2)return false;
                    if(pre>a->val)pre=a->val;
                    else{
                        cout<<lvl<<endl;
                        return false;
                    }
                }
                if(a->left)q.push(a->left);
                if(a->right)q.push(a->right);
            }
            lvl++;
        }
        cout<<lvl<<endl;
        return true;
    }
};
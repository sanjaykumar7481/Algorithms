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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int,TreeNode*>mp;
        unordered_map<int,int>map;
        for(int i=0;i<des.size();i++)
        {
            if(mp.find(des[i][0])==mp.end())
            {
                TreeNode* par=new TreeNode(des[i][0]);
                mp[par->val]=par;
                map[par->val]++;
                if(mp.find(des[i][1])==mp.end())
                {
                    TreeNode* child=new TreeNode(des[i][1]);
                    mp[child->val]=child;
                    if(des[i][2]==1)par->left=child;
                    else par->right=child;
                    map[child->val]++;
                }
                else
                {
                    if(des[i][2]==1)par->left=mp[des[i][1]];
                    else par->right=mp[des[i][1]];
                }
            }
            else
            {
                if(mp.find(des[i][1])==mp.end())
                {
                    TreeNode* child=new TreeNode(des[i][1]);
                    mp[child->val]=child;
                    if(des[i][2]==1)mp[des[i][0]]->left=child;
                    else mp[des[i][0]]->right=child;
                    map[child->val]++;
                }
                else
                {
                    if(des[i][2]==1)mp[des[i][0]]->left=mp[des[i][1]];
                    else mp[des[i][0]]->right=mp[des[i][1]];
                }
            }
            
        }
        for(auto i:des)
        {
            // cout<<i.first<<" ";
            map.erase(i[1]);
        }
        TreeNode* root=NULL;
        for(auto i:map)
        {
            root=mp[i.first];
            // TreeNode *root=mp[i.first];
            // break;
        }
        return root;
    }
};
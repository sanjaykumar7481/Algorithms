/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    unordered_map<TreeNode*,unordered_map<ListNode*,bool>>dp;
    bool fun(ListNode *head,TreeNode *root,ListNode *init)
    {
        if(!head)return true;
        if(!root)return false;
        if(dp[root].find(head)!=dp[root].end())return dp[root][head];
        bool ans=false;
        if(head->val==root->val)
        {
            ans=fun(head->next,root->left,init) or fun(head->next,root->right,init);
        }
        if(head!=init and init->val==root->val)init=init->next;
        return dp[root][head]=ans or fun(init,root->left,init) or fun(init,root->right,init);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return fun(head,root,head);
    }
};
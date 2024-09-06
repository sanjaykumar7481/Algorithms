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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        ListNode *temp=head,*res=NULL,*prev=NULL;
        while(temp)
        {
            if(mp.find(temp->val)!=mp.end())
            {
                if(prev)
                {
                    prev->next=temp->next;
                }
            }
            else prev=temp;
            if(!res)res=prev;
            temp=temp->next;
        }
        return res;
    }
};
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>mp;
        ListNode *temp=head;
        int s=0;
        while(temp)
        {
            s+=temp->val;
            if(s==0)
            {
                head=temp->next;
                mp.clear();
            }
            else if(mp.find(s)!=mp.end())
            {
                ListNode *temp2=mp[s]->next;
                int temp_sum=s;
                while(temp2!=temp)
                {
                    temp_sum+=temp2->val;
                    mp.erase(temp_sum);
                    temp2=temp2->next;
                }
                mp[s]->next=temp->next; 
            }
            else mp[s]=temp;
            temp=temp->next;
        }
        return head;
    }
};
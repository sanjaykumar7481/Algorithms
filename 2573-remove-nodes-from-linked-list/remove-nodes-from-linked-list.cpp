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
    ListNode* removeNodes(ListNode* head) {
        ListNode *rev=NULL;
        while(head)
        {
            ListNode *temp=head->next;
            head->next=rev;
            rev=head;
            head=temp;
        }
        int maxi=0;
        ListNode *prev=rev,*res=prev;
        while(rev)
        {
            if(maxi>rev->val)
            {
                // cout<<prev->val<<" ";
                prev->next=rev->next;
                rev=rev->next;
            }
            else
            {
                maxi=rev->val;
                prev=rev;
                rev=rev->next;
            }
            // cout<<rev->val<<" ";
            // rev=rev->next;
        }
        while(res)
        {
            ListNode *temp=res->next;
            res->next=rev;
            rev=res;
            res=temp;
        }
        return rev;
    }
};
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
    void fun(ListNode *head,int &carry)
    {
        if(!head)return;
        fun(head->next,carry);
        head->val+=carry+head->val;
        carry=head->val/10;
        head->val=head->val%10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        fun(head,carry);
        ListNode *nn;
        if(carry!=0)
        {
            nn=new ListNode(carry);
            nn->next=head;
            head=nn;
        }
        return head;
    }
};
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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        ListNode* cur=head;
        while(cur)
        {
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
        
    }
    void reorderList(ListNode* head) {
        ListNode* h=head;
        ListNode* t=head;
        ListNode* first=head;
        while(h and h->next!=NULL )
        {
            t=t->next;
            h=h->next->next;
        }
        ListNode* second=reverse(t->next);
        t->next=NULL;
        while(second)
        {
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};
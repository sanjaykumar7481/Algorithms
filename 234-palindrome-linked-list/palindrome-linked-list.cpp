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
    bool isPalindrome(ListNode* head) {
        ListNode* t=head;
        ListNode* p=head;
        while(p)
        {
            if(p->next)
            p=p->next->next;
            else break;
            t=t->next;
        }
        ListNode* r=NULL;
        while(t)
        {
            ListNode* s=t->next;
            t->next=r;
            r=t;
            t=s;
        }
        while(r)
        {
            if(head->val!=r->val) return false;
            head=head->next;
            r=r->next;
        }
        return true;
    }
};
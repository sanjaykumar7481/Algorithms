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
    int gcd(int a,int b)
    {
        if(b==0)return a;
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *temp=head;
        while(temp)
        {
            ListNode *itr=temp->next;
            if(!itr)break;
            ListNode *nn=new ListNode(gcd(temp->val,itr->val));
            temp->next=nn;
            nn->next=itr;
            temp=itr;
        }
        return head;
    }
};
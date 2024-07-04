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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *res=NULL,*result;
        head=head->next;
        while(head)
        {
            int sum=0;
            while(head and head->val!=0)
            {
                sum+=head->val;
                head=head->next;
            }
            head->val=sum;
            if(!res)
            {
                res=head;
                result=res;
            }
            else 
            {
                res->next=head;
                res=res->next;
            }
            head=head->next;
        }
        return result;
    }
};
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int c=0;
        ListNode *res=list1,*last=list2;
        while(last->next)last=last->next;
        while(list1)
        {
            if(c==a-1)
            {
                ListNode *Left=list1;
                while(c<=b)
                {
                    list1=list1->next;
                    c++;
                }
                Left->next=list2;
                last->next=list1;
                return res;
            }
            c++;
            list1=list1->next;
        }
        return NULL;
    }
};
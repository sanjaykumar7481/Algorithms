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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>res(k);
        ListNode *size=head;
        int length=0;
        while(size)
        {
            length++;
            size=size->next;
        }
        int rem=length%k,ksize=length/k,c=0;
        ListNode *itr=head,*end;
        while(itr)
        {
            bool boolean=true;
            for(int i=0;i<ksize;i++)
            {
                boolean=false;
                if(i==0)res[c++]=itr;
                end=itr;
                itr=itr->next;
            }
            if(rem)
            {
                rem--;
                end=itr;
                itr=itr->next;
            }
            if(boolean)res[c++]=end;
            end->next=NULL;
        }
        return res;
    }
};
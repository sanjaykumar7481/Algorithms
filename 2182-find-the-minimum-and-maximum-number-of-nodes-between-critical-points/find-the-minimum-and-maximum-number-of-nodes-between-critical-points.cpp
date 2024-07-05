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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int for_max=-1,for_min=1e9,pre=head->val,c=0,ind=-1,first=-1;
        head=head->next;
        while(head->next)
        {
            if((pre<head->val and head->next->val<head->val) or (pre>head->val and head->next->val>head->val))
                {
                
                    if(ind!=-1){
                        // cout<<head->val<<" ";
                        for_max=max(for_max,c-first);
                        for_min=min(for_min,c-ind);
                    }
                    if(first==-1)first=c;
                    ind=c;
                }
            c++;
            pre=head->val;
            head=head->next;
        }
        if(for_max==-1 or for_min==1e9)return {-1,-1};
        return {for_min,for_max};
    }
};
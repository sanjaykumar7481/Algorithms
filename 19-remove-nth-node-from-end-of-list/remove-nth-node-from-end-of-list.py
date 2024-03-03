# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head.next:
            return None
        t=s=head
        c=0
        while(t):
            t=t.next
            c+=1
        k=0
        temp=head
        prev=head
        if c==n:
            return head.next
            
        while(temp):
            k+=1
            if(k==c-n):
                if(temp.next.next):
                    temp.next=temp.next.next
                else:
                    temp.next=None
            temp=temp.next
        return head
                
            
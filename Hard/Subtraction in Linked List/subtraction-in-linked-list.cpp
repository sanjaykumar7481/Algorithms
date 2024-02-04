//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        Node *s1=NULL,*s2=NULL,*rev1=NULL,*rev2=NULL;
        int c1=0,c2=0;
        Node *first,*second;
        Node *dup1=new Node(0),*dup2=new Node(0);
        Node *temp1=dup1,*temp2=dup2;
        while(head1)
        {
            if(head1->data!=0 and !s1)s1=head1;
            if(s1)
            {
                dup1->next=new Node(head1->data);
                dup1=dup1->next;
                Node *temp=head1->next;
                head1->next=rev1;
                rev1=head1;
                head1=temp;
                c1++;
            }
            else head1=head1->next;
        }
        while(head2)
        {
            if(head2->data!=0 and !s2)s2=head2;
            if(s2)
            {
                 dup2->next=new Node(head2->data);
                dup2=dup2->next;
                Node *temp=head2->next;
                head2->next=rev2;
                rev2=head2;
                head2=temp;
                c2++;
            }
            else head2=head2->next;
        }
        if(!s1 and !s2)
        {
            // cout<<"ss";
            return new Node(0);
        }
        if(!s1)return temp2->next;
        if(!s2)return temp1->next;
        if(c1>c2)
        {
            first=rev1;
            second=rev2;
        }
        else if(c1==c2)
        {
            while(temp1 and temp2 and temp1->data==temp2->data)
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
            if(!temp1 or !temp2)return new Node(0);
            if(temp1->data>temp2->data)
            {
                first=rev1;
                second=rev2;
            }
            else
            {
                first=rev2;
                second=rev1;
            }
            
        }
        else{
            first=rev2;
            second=rev1;
        }
        Node *n=new Node(0);
        Node *p=n;
        int carry=0;
        while(first and second)
        {
            first->data-=carry;
            if(first->data<second->data)
            {
                if(first->data<0)first->data=9;
                else if(first->data==0)first->data=10;
                else first->data+=10;
                carry=1;
            }
            else carry=0;
            n->next=new Node(first->data-second->data);
            n=n->next;
            first=first->next;
            second=second->next;
        }
        while(first)
        {
            first->data-=carry;
            if(first->data<0)
            {
                first->data=9;
                carry=1;
            }
            else carry=0;
            if(first->next==NULL and first->data==0)break;
            n->next=new Node(first->data);
            n=n->next;
            first=first->next;
        }
        Node *res=NULL;
        p=p->next;
        while(p)
        {
            Node *temp=p->next;
            p->next=res;
            res=p;
            p=temp;
        }
        while(res)
        {
            if(res->data!=0)return res;
            res=res->next;
        }
        return new Node(0);
        // return NULL;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends
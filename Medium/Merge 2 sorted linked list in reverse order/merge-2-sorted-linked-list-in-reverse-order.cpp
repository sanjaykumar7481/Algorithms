//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node *a=node1,*b=node2;
        Node *s=NULL,*start=NULL;
        while(a and b)
        {
            if(a->data<=b->data)
            {
                Node *temp=a->next;
                a->next=NULL;
                if(s){
                    s->next=a;
                    s=s->next;
                }
                else{
                    s=a;
                    start=s;
                }
                a=temp;
            }
            else
            {
                Node *temp=b->next;
                b->next=NULL;
                if(s){
                    s->next=b;
                    s=s->next;
                }
                else{
                    s=b;
                    start=s;
                }
                b=temp;
            }
        }
        if(a){
            if(s)s->next=a;
            else start=a;;
        }
        if(b){
            if(s)s->next=b;
            else start=b;
        }
        Node *rev=NULL;
        while(start)
        {
            Node *temp=start->next;
            start->next=rev;
            rev=start;
            start=temp;
        }
        return rev;
        // return start;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends
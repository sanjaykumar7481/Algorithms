//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution {
public:
    Node *flatten(Node *root)
    {
        // Your code here
        Node *result=NULL;
        while(root)
        {
            Node *temp=root->next,*ans=NULL,*head=NULL;
            while(root and result)
            {
                if(root->data<result->data)
                {
                    Node *a=root->bottom;
                    root->bottom=NULL;
                    if(!ans)
                    {
                        ans=root;
                        head=ans;
                    }
                    else{
                        ans->bottom=root;
                        ans=ans->bottom;
                    }
                    root=a;
                }
                else
                {
                    Node *b=result->bottom;
                    result->bottom=NULL;
                    if(!ans)
                    {
                        ans=result;
                        head=ans;
                    }
                    else{
                        ans->bottom=result;
                        ans=ans->bottom;
                    }
                    result=b;
                }
            }
            while(root)
            {
                 Node *a=root->bottom;
                    root->bottom=NULL;
                    if(!ans)
                    {
                        ans=root;
                        head=ans;
                    }
                    else{
                        ans->bottom=root;
                        ans=ans->bottom;
                    }
                    root=a;
            }
            if(result)ans->bottom=result;
            result=head;
            root=temp;
        }
        return result;
    }
};


//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node * temp = NULL;
        struct Node * head = NULL;
        struct Node * pre = NULL;
        struct Node * tempB = NULL;
        struct Node * preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Solution ob;
        Node* root = ob.flatten(head);
        printList(root);
        cout << endl;

    }
    return 0;
}

// } Driver Code Ends
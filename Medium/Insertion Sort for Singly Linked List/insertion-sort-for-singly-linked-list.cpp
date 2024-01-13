//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        Node *temp=head_ref;
        if(!temp or !temp->next)return temp;
        Node *head=head_ref;
        Node *head_prev;
        while(head and head->next)
        {
            temp=head_ref;
            head_prev=head;
            head=head->next;
            Node *connect=NULL;
            while(temp!=head and head->data >temp->data)
            {
                connect=temp;
                temp=temp->next;
            }
            // if(connect)
            // cout<<head->data<<"-"<<connect->data<<endl;
            // else cout<<head->data<<"-"<<"first"<<endl;
            if(temp!=head)
            {
                // cout<<"YES"<<endl;
                head_prev->next=head->next;
                if(!connect)
                {
                    head->next=head_ref;
                    head_ref=head;
                }
                else{
                    Node *next_node=connect->next;
                    connect->next=head;
                    head->next=next_node;
                }
            head=head_prev;
            }
            else{
                // cout<<"NO"<<endl;
                // head=head->next;
            }
        }
        return head_ref;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    void merge(Item *arr,int l,int m,int h)
    {
        int n1=m-l+1,n2=h-m;
        Item temp1[n1],temp2[n2];
        int i=0,j=0,k=l;
        for(int p=0;p<n1;p++)temp1[p]=arr[l+p];
        for(int p=0;p<n2;p++)temp2[p]=arr[m+1+p];
        while(i<n1 && j<n2)
        {
            if(((temp1[i].value)/double(temp1[i].weight))>=((temp2[j].value)/double(temp2[j].weight)))
            {
                arr[k]=temp1[i];
                i++;
            }
            else
            {
                arr[k]=temp2[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            arr[k++]=temp1[i++];
        }
        while(j<n2)arr[k++]=temp2[j++];
        return;
    }
    void sort(Item *arr,int l,int h)
    {
        if(l<h)
        {
            int m=(l+h)/2;
            sort(arr,l,m);
            sort(arr,m+1,h);
            merge(arr,l,m,h);
        }
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans=0;
        sort(arr,0,n-1);
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight<=W)
            {
                W-=arr[i].weight;
                ans+=arr[i].value;
            }
            else if(W!=0 and W-arr[i].weight<0)
            {
                ans+=(arr[i].value/double(arr[i].weight))*W;
                W=0;
            }
            // cout<<arr[i].value<<"-"<<arr[i].weight<<" ";
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
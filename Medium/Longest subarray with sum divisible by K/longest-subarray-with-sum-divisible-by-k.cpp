//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int>mp;
	    mp[0]=-1;
	    int s=0,ans=0;
	    for(int i=0;i<n;i++)
	    {
	        s+=arr[i];
	        int p=s%k;
	        if(p<0)p+=k;
	        if(mp.find(p)==mp.end())mp[p]=i;
	        else ans=max(ans,i-mp[p]);
	       // if(s==0)ans=max(ans,i+1);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends
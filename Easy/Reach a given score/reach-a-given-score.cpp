//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    int fun(int i,int n,vector<int>&res,vector<vector<int>>&dp)
    {
        if(n==0)return 1;
        if(n<0)return 0;
        int c=0;
        if(dp[i][n]!=-1)return dp[i][n];
        for(int j=i;j<3;j++)
        {
            if(n-res[j]>=0)c+=fun(j,n-res[j],res,dp);
        }
        return dp[i][n]=c;
    }
    long long int count(long long int n)
    {
    	// Your code here
    	vector<vector<int>>dp(3,vector<int>(n+1,-1));
    	vector<int>res={3,5,10};
    	return fun(0,n,res,dp);
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
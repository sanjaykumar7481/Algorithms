//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int fun(int i,int n,int total,vector<int>&cost,vector<vector<int>>&dp)
    {
        if(i>=n or total==0)return 0;
        if(dp[i][total]!=-1)return dp[i][total];
        if(cost[i]<=total)
        {
            // cout<<cost[i]<<" ";
            return dp[i][total]=max(1+fun(i+1,n,total-cost[i]+floor(cost[i]*(9/10.0)),cost,dp),fun(i+1,n,total,cost,dp));
        }
        return dp[i][total]=fun(i+1,n,total,cost,dp);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return fun(0,n,total,cost,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends
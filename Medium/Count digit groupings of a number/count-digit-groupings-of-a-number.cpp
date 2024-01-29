//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int fun(int i,int n,int prev,string &str,vector<vector<int>>&dp)
	{
	    if(i>=n)
	    {
	        return 1;
	    }
	    if(dp[i][prev]!=-1)return dp[i][prev];
	    int a=0,ans=0;
	    string p;
	    for(int j=i;j<n;j++)
	    {
	        a+=str[j]-'0';
	        if(a>=prev)
	        {
	            ans+=fun(j+1,n,a,str,dp);
	        }
	    }
	    return dp[i][prev]=ans;
	    
	}
	int TotalCount(string str){
	    // Code here
	    int r=0;
	    for(auto i:str)r+=i-'0';
	    vector<vector<int>>dp(str.size(),vector<int>(r+1,-1));
	    return fun(0,str.size(),0,str,dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
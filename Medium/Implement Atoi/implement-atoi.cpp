//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        bool f=false;
        if(s[0]=='-')f=true;
        int ans=0,i=0;
        if(f)i=1;
        for(;i<s.size();i++)
        {
            int p=s[i]-'0';
            if(p<0 or p>9)return -1;
            ans=ans*10 +p;
        }
        if(f)return -1*ans;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int fun(int i,int j,int k,int n1,int n2,int n3,string &A,string &B,string &C,vector<vector<vector<int>>>&res,string &p)
        {
            if(i>=n1 or j>=n2 or k>=n3)
            {
                // cout<<p<<"-";
                return 0;
            }
            if(res[i][j][k]!=-1)return res[i][j][k];
            int a=0;
            if(A[i]==B[j] and A[i]==C[k])
            {
                p+=A[i];
                a=1+fun(i+1,j+1,k+1,n1,n2,n3,A,B,C,res,p);
                p.pop_back();
            }
            else if(A[i]==B[j])a= max(fun(i,j,k+1,n1,n2,n3,A,B,C,res,p),fun(i+1,j+1,k,n1,n2,n3,A,B,C,res,p));
            else if(A[i]==C[k])a= max(fun(i,j+1,k,n1,n2,n3,A,B,C,res,p),fun(i+1,j,k+1,n1,n2,n3,A,B,C,res,p));
            else if(B[j]==C[k])a= max(fun(i+1,j,k,n1,n2,n3,A,B,C,res,p),fun(i,j+1,k+1,n1,n2,n3,A,B,C,res,p));
            else a=max(fun(i+1,j,k,n1,n2,n3,A,B,C,res,p),max(fun(i,j+1,k,n1,n2,n3,A,B,C,res,p),fun(i,j,k+1,n1,n2,n3,A,B,C,res,p)));
            res[i][j][k]=a;
        }
            
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            string res;
            vector<vector<vector<int>>>dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
            return fun(0,0,0,n1,n2,n3,A,B,C,dp,res);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long mod=1e9+7;
    long long fun(int i,int s,int n)
    {
       if(i>s)return 0;
       long long a=1;
       for(int j=1;j<=i;j++)
       {
           a=((a%mod)*(n++))%mod;
       }
       return (a%mod +fun(i+1,s,n)%mod)%mod;
    }
    long long sequence(int s){
        // code here
        return fun(1,s,1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
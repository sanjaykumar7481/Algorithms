//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void construct(vector<int>&sieve)
    {
        for(int i=3;i*i<sieve.size();i++)
        {
            if(sieve[i]==i)
            {
                for(int j=i*i;j<sieve.size();j+=i)if(sieve[j]==j)sieve[j]=i;
            }
        }
    }
    int kthPrime(int n, int k){
        // code here
        vector<int>sieve(n+1,0);
        for(int i=0;i<=n;i++)sieve[i]=i;
        vector<int>res;
        for(int i=4;i<=n;i+=2)sieve[i]=2;
        construct(sieve);
        int level=0,c=0;
        while(n!=1)
        {
            level=sieve[n];
            n/=level;
            res.push_back(level);
            c++;
        }
        // cout<<c<<endl;
        // for(auto i:res)cout<<i<<" ";
        // cout<<sieve[1123];
        if(k>c)return -1;
        return res[k-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        
        Solution ob;
        cout<<ob.kthPrime(n, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
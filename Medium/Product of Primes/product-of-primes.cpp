//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void construct(vector<int>&sieve,int size)
    {
        for(int i=2;i*i<=size;i++)
        {
            if(sieve[i])
            {
                for(int j=i*i;j<=size;j+=i)sieve[j]=0;
            }
        }
    }
    long long primeProduct(long long L, long long R){
        // code here
        int size=sqrt(R);
        vector<int>sieve(size+1,1);
        vector<int>result(R-L+1,1);
        construct(sieve,size);
        // for(int i=2;i<sieve.size();i++)if(sieve[i])cout<<i<<" ";
        // cout<<endl;
        for(int i=2;i<sieve.size();i++)
        {
            if(sieve[i])
            {
                int p;
                    p=i*(L/i);
                    p+=L%i?i:0;
                    p-=L;
                if(i>L)p+=i;
                for(int j=p;j<result.size();j+=i)result[j]=0;
            }
        }
        long long int ans=1,mod=1e9+7;
        for(int i=0;i<result.size();i++)
        {
            if(result[i])
            {
                // cout<<L+i<<" ";
                ans=((ans%mod)*(L+i))%mod;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        long long int temp=N;
        long long int ans;
        if(N%2==0)ans=2;
        else ans=1;
        while(N%2==0)N/=2;
        for(int i=3;i*i<=N;i+=2)
        {
            while(N%i==0)
            {
                ans=i;
                N/=i;
            }
        }
        // cout<<N<<" "<<ans<<endl;
        if(N>2)return N;
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
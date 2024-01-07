//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int possible(int N,int m,int k,int arr[])
    {
        int s=0,c=0;
        for(int i=0;i<N;i++)
        {
            if(s+arr[i]<=m)s+=arr[i];
            else{
                s=arr[i];
                c++;
            }
        }
        return c+1;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int l=0,r=0,ans=0;
        for(int i=0;i<N;i++)
        {
            l=max(l,arr[i]);
            r+=arr[i];
        }
        while(l<=r)
        {
            int m=(l+r)/2;
            int p=possible(N,m,K,arr);
            if(p<=K)
            {
                // cout<<p<<" "<<m<<endl;
                r=m-1;
                ans=m;
                
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
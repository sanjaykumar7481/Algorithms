//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool possible(int n,int m,int k,vector<int>&arr)
    {
        int stall=arr[0];
        k--;
        for(int i=0;i<n;i++)
        {
            if(arr[i]-stall>=m)
            {
                stall=arr[i];
                k--;
                if(k==0)return true;
                if(n-i-1<k)return false;
            }
            
        }
        return (k<=0);
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int l=1,r=stalls[n-1]-stalls[0],ans=-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(possible(n,m,k,stalls))
            {
                l=m+1;
                ans=m;
                // cout<<ans<<endl;
            }
            else r=m-1;
        }
        return ans;
        // Write your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
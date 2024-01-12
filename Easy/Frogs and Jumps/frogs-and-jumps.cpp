//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int>sieve(leaves+1,1);
        int c=0;
        for(int i=0;i<N;i++)
        {
            if(frogs[i]<=leaves and sieve[frogs[i]])
            for(int j=frogs[i];j<=leaves;j+=frogs[i])sieve[j]=0;
        }
        for(int i=1;i<=leaves;i++)if(sieve[i]!=0)c++;
        return c;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends
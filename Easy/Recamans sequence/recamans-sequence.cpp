//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        vector<int>res(n,0);
        unordered_map<int,int>mp;
        res[0]=0;
        mp[0]=0;
        for(int i=1;i<n;i++)
        {
            if(mp.find(res[i-1]-i)==mp.end() and res[i-1]-i>0)res[i]=res[i-1]-i;
            else res[i]=res[i-1]+i;
            mp[res[i]]=0;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
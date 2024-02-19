//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        priority_queue<int>pq;
        int arr[26]={0};
        for(auto i:s)arr[i-'a']++;
        for(int i=0;i<26;i++)if(arr[i]!=0)pq.push(arr[i]);
        while(k--)
        {
            int a=pq.top();
            a--;
            pq.pop();
            pq.push(a);
        }
        int ans=0;
        while(!pq.empty())
        {
            int a=pq.top();
            ans+=(a*a);
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
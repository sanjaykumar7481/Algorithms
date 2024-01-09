//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n){
        // code here
        vector<int>v(1e5,0);
    v[0]=1;
    int c=0,range=0,j=0;
    for(int i=1;i<=n;i++)
    {
        bool b=false;
        c=0;
        for(j=0;j<=range;j++)
        {
            v[j]=(v[j]*i)+c;
            c=v[j]/10;
            v[j]=v[j]%10;
        }
        if(c>0)j=range+1;
        while(c>0)
        {
            v[j]+=c;
            v[j]%=10;
            c/=10;
            range++;
            j++;
        }
    }
    // cout<<range<<endl;
    vector<int>res;
    for(int i=range;i>=0;i--)
    {
        // cout<<v[i]<<" ";
        res.push_back(v[i]);
    }
    return res;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
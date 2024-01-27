//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int fun(int A[],int l,int h,int key)
    {
        if(l>h)return -1;
        int m=(l+h)/2;
        if(A[m]==key)return m;
        if(A[l]<A[m])
        {
            if(key>=A[l] and key<A[m])return fun(A,l,m-1,key);
            return fun(A,m+1,h,key);
        }
        else
        {
            if(key>A[m] and key<=A[h])return fun(A,m+1,h,key);
            return fun(A,l,m-1,key);
        }
    }
    int search(int A[], int l, int h, int key){
        if(h-l==1)
        {
            if(A[l]==key)return l;
            if(A[h]==key)return h;
            return -1;
        }
        return fun(A,l,h,key);
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends
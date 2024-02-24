//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int fun(int n)
        {
            int s=n/2 + n/3 + n/4;
            if(n>=s)
            {
                return n;
            }
            int a=fun(n/2);
            int b=fun(n/3);
            int c=fun(n/4);
            // cout<<n<<" "<<p<<endl;
            return a+b+c;
        }
        int maxSum(int n)
        {
            //code here.
            return fun(n);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
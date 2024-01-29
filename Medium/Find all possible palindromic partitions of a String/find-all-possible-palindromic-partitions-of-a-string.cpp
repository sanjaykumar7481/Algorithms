//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void fun(int i,string &s,vector<string>&res,vector<vector<string>>&ans)
    {
        if(i>=s.size())
        {
            ans.push_back(res);
        }
        string p;
        for(int j=i;j<s.size();j++)
        {
            p+=s[j];
            string t=p;
            reverse(t.begin(),t.end());
            if(p==t)
            {
                res.push_back(p);
                fun(j+1,s,res,ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>>ans;
        vector<string>res;
        fun(0,S,res,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
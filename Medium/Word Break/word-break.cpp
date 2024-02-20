//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    bool fun(int i,int j,string &s,unordered_map<string,int>&mp,string t)
    {
        if(i>=s.size())return true;
        if(j>=s.size())return false;
        t+=s[j];
        if(mp.find(t)!=mp.end())
        {
            // cout<<t<<" ";
            return fun(j+1,j+1,s,mp,"") or fun(i,j+1,s,mp,t);
        }
        return fun(i,j+1,s,mp,t);
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_map<string,int>mp;
        for(auto i:dictionary)mp[i]=0;
        return fun(0,0,s,mp,"");
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends
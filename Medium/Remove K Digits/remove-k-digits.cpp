//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
        vector<int>st;
        int i=0;
        while(i<S.size())
        {
            int p=S[i]-'0';
            while(!st.empty() and st.back()>p and k)
            {
                st.pop_back();
                k--;
            }
            st.push_back(p);
            i++;
        }
        i=0;
        while(st[i]==0 and i<st.size()-1)i++;
        vector<int> ans;
        for(int j=i;j<st.size();j++)ans.push_back(st[j]);
        while(k-- and !ans.empty()){
            ans.pop_back();
        }
        string result;
        for(auto j:ans)result+=to_string(j);
        if(result=="")return "0";
        return result;
        // return "";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void fun(int i,string &s,vector<string>&res,string temp)
	    {
	        if(i>=s.size()){
	            if(temp.size()>0)
	            res.push_back(temp);
	            return;
	        }
	        fun(i+1,s,res,temp);
	        fun(i+1,s,res,temp+s[i]);
	        return;
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		  //  sort(s.begin(),s.end());
		    vector<string>res;
		    fun(0,s,res,"");
		    sort(res.begin(),res.end());
		    return res;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
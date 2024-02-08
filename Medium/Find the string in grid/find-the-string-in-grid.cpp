//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool fun(int i,int j,vector<vector<char>>&grid,string &word,int k,int x,int y)
    {
        if(k>=word.size())return true;
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())
        {
         return k>=word.size();   
        }
        if(grid[i][j]!=word[k])return false;
        return fun(i+x,j+y,grid,word,k+1,x,y);
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>>res;
	    vector<vector<int>>dir={{1,0},{0,1},{1,1},{-1,-1},{0,-1},{-1,0},{1,-1},{-1,1}};
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<grid[0].size();j++)
	        {
	            if(grid[i][j]!=word[0])continue;
	            bool a=false;
	            for(int k=0;k<8;k++)
	            {
	                a=a or fun(i,j,grid,word,0,dir[k][0],dir[k][1]);
	                if(a)
	                {
	                    res.push_back({i,j});
	                    break;
	                }
	            }
	        }
	    }
	   // for(auto i:res)cout<<i[0]<<" "<<i[1]<<endl;
	   // cout<<endl;
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    int fun(int i,int pre,vector<vector<int>>&graph,vector<int>&vis)
    {
        vis[i]=1;
        for(auto k:graph[i])
        {
            if(k!=pre)
            {
                if(vis[k])return 0;
                int p=fun(k,i,graph,vis);
                if(p==0)return 0;
            }
        }
        return 1;
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<vector<int>>graph(n);
        for(auto i:adj)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        int k=fun(0,-1,graph,vis);
        for(auto i:vis)if(i==0)return 0;
        return k;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
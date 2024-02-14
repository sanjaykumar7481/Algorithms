//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int,int>ladders,snakes;
        for(int i=0;i<2*N;i+=2)
        {
            if(arr[i]<arr[i+1])ladders[arr[i]]=arr[i+1];
            else snakes[arr[i]]=arr[i+1];
        }
        queue<int>q;
        vector<int>res(31,-1);
        res[1]=0;
        q.push(1);
        while(!q.empty())
        {
            auto a=q.front();
            q.pop();
            for(int j=1;j<=6 and a+j<=30;j++)
            {
                int dis;
                if(res[a+j]==-1)
                {
                    if(ladders.find(a+j)!=ladders.end())
                    {
                        dis=ladders[a+j];
                        if(res[dis]==-1)
                        {
                            q.push(dis);
                            res[dis]=1+res[a];
                        }
                        else res[dis]=min(res[dis],1+res[a]);
                        res[a+j]=1+res[a];
                    }
                    else if(snakes.find(a+j)!=snakes.end())
                    {
                        dis=snakes[a+j];
                        if(res[dis]==-1)
                        {
                            q.push(dis);
                            res[dis]=1+res[a];
                        }
                        else res[dis]=min(res[dis],1+res[a]);
                        res[a+j]=1+res[a];
                    }
                    else
                    {
                        res[a+j]=1+res[a];
                        q.push(a+j);
                    }
                }
                else
                {
                    res[a+j]=min(res[a+j],1+res[a]);
                }
            }
        }
        return res[30];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
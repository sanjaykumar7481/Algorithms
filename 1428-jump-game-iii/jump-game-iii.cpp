int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
    bool dfs(int i,vector<int>&arr,vector<int>&vis)
    {
        if(i<0 or i>=arr.size() or vis[i])return false;
        if(arr[i]==0)return true;
        vis[i]=1;
        return dfs(i+arr[i],arr,vis) or dfs(i-arr[i],arr,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0);
        return dfs(start,arr,vis);
    }
};
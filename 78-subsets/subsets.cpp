class Solution {
public:
    void fun(int i,vector<int> &nums,int n,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(i==n)
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        fun(i+1,nums,n,ds,ans);
        ds.pop_back();
        // backtracking
        fun(i+1,nums,n,ds,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>> ans;
        fun(0,nums,nums.size(),ds,ans);
        return ans;
    }
};
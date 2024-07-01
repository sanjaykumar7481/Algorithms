class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),ans=0;
        vector<int>Max(n);
        Max[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            Max[i]=max(Max[i+1],prices[i]);
        }
        for(int i=0;i<n-1;i++)
        {
            ans=max(ans,Max[i+1]-prices[i]);
        }
        return ans;
    }
};
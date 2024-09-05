class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        for(auto i:rolls)sum+=i;
        mean*=(n+rolls.size());
        mean-=sum;
        if(mean<=0 or (mean/6.0)>n or (mean/n)==0)return {};
        vector<int>ans(n,mean/n);
        int rem=mean%n;
        for(int i=0;i<rem;i++)ans[i]++;
        return ans;
    }
};
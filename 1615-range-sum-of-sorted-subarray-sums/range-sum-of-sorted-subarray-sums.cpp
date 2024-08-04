class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>total(1e5+1,0);
        long long mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            int s=0;
            for(int j=i;j<n;j++)
            {
                s+=nums[j];
                total[s]++;
            }
        }
        vector<int>prev(1,0);
        for(int i=0;i<=1e5;i++)
        {
            while(total[i])
            {
                prev.push_back((prev[prev.size()-1]%mod + i%mod)%mod);
                total[i]--;
            }
        }
        if(left==1)return prev[right];
        if(left==right)return prev[left]-prev[left-1];
        return prev[right]-prev[left-1];
    }
};
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int s=0;
        unordered_map<int,int>mp;
        int zero_ans=0,c=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)c++;
            else{
                zero_ans+=(c*(c+1))/2;
                c=0;
            }
            s+=nums[i];
            if(mp.find(s)==mp.end())mp[s]=i;
        }
        zero_ans+=(c*(c+1))/2;
        if(goal>s)return 0;
        if(goal==0)return zero_ans;
        int fixed=goal,right,left,res=0;
        while(goal<=s)
        {
            int next=goal+1;
            int pre=goal-fixed;
            if(mp.find(next)!=mp.end())right=mp[next]-mp[goal]-1;
            else right=n-1-mp[goal];
            if(mp.find(pre)!=mp.end())
            {
                left=mp[pre+1]-mp[pre]-1;
                if(pre==0)left++;
            }
            else left=0;
            res+=(left*right)+left+right+1;
            goal++;
        }
        return res;
    }
};
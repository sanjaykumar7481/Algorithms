class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res=0,ans=0;
        for(int i=0;i<grumpy.size();i++)
        {
            if(grumpy[i]==0)res+=customers[i];
        }
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i])res+=customers[i];
        }
        ans=max(ans,res);
        int j=0;
        for(int i=minutes;i<grumpy.size();i++)
        {
            if(grumpy[j])res-=customers[j];
            j++;
            if(grumpy[i])res+=customers[i];
            ans=max(ans,res);
        }
        return ans;
    }
};
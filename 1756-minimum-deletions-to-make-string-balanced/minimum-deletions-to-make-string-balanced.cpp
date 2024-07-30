class Solution {
public:
    int minimumDeletions(string s) {
        vector<int>prev(s.size(),0),after(s.size(),0);
        int ans=s.size(),n=ans;
        prev[0]=s[0]=='b'?1:0;
        after[n-1]=s[n-1]=='a'?1:0;
        for(int i=1;i<n;i++)
        {
            prev[i]+=prev[i-1];
            if(s[i]=='b')prev[i]+=1;
        }
        for(int i=n-2;i>=0;i--)
        {
            after[i]+=after[i+1];
            if(s[i]=='a')after[i]+=1;
        }
        for(int i=0;i<n;i++)
        {
            int as=i-1>=0?prev[i-1]:0;
            int bs=i+1<n?after[i+1]:0;
            ans=min(ans,as+bs);
        }
        return ans;
    }
};
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int c=0,t=right;
        while(t)
        {
            c++;
            t>>=1;
        }
        int ans=0;
        for(int i=c-1;i>=0;i--)
        {
            if((left&(1<<i)) and (right&(1<<i)))ans+=(1<<i);
            else if((left&(1<<i))==0 and (right&(1<<i)))break;
        }
        // cout<<c<<endl;
        return ans;
    }
};
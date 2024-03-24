class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int msb=nums.size()-1,c=0;
        while(msb){
            msb>>=1;
            c++;
        }
        vector<int>temp(c,0);
        for(auto i:nums)
        {
            for(int j=0;j<32;j++)if(i&(1<<j))temp[j]++;
        }
        int n=nums.size();
        int p=2,res=1,ans=0;
        for(int i=0;i<c;i++)
        {
            int k=n/p;
            int mod=n%p;
            k=(k*res);
            k+=mod>p/2?(mod-p/2):0;
            cout<<temp[i]<<" "<<k<<endl;
            if(temp[i]>k)ans|=(1<<i);
            res=p;
            p*=2;
        }
        return ans;
    }
};
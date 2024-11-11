class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int>res;
        vector<int>Sieve(10001,1);
        Sieve[0]=0;
        Sieve[1]=0;
        for(int i=2;i*i<Sieve.size();i++){
            if(Sieve[i]==0)continue;
            for(int j=i*i;j<Sieve.size();j+=i)Sieve[j]=0;
        }
        for(int i=2;i<Sieve.size();i++)if(Sieve[i])res.push_back(i);
        int pre=0;
        for(int i=0;i<nums.size();i++)
        {
            auto pos=lower_bound(res.begin(),res.end(),nums[i]-pre)-res.begin();
            if(pos!=0){
                nums[i]-=res[pos-1];
            }
            pre=nums[i];
            if(i>0 and nums[i-1]>=nums[i])return false;
        }
        return true;
    }
};
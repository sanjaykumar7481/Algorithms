class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        int st=0;
        while(st<n)
        {
            bool f=true;
            int temp=nums[st];
            if(temp!=-1)nums[st]=0;
            // else continue;
            while(f and temp>0)
            {
                // cout<<temp<<" ";
                int ans=temp%n;
                if(nums[ans]==0)
                {
                    f=false;
                    nums[ans]=-1;
                    // cout<<endl;
                    break;
                }
                if(nums[ans]==-1)
                {
                    f=false;
                    res.push_back(temp);
                    // cout<<endl;
                    break;
                }
                temp=nums[ans];
                nums[ans]=-1;
            }
            st++;
        }
        // cout<<endl;
        // for(auto i:nums)cout<<i<<" ";
        return res;
    }
};
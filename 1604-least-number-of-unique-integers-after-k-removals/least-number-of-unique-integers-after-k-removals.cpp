class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto i:arr)mp[i]++;
        map<int,vector<int>>res;
        for(auto i:mp)
        {
            res[i.second].push_back(i.first);
        }
        int ans=0,sum=0,considered=0;
        for(auto i:res)
        {
            int minus=i.first*i.second.size();
            if(ans+minus>k and k!=0)
            {
                int p=(k-ans);
                considered+=(p/i.first);
                // if(p%i.first)considered++;
                k=0;
            }
            else if(k!=0)
            {
                ans+=minus;
                considered+=i.second.size();
            }
            sum+=i.second.size();
        }
        // cout<<sum<<" "<<considered<<endl;
        return sum-considered;
    }
};
class Solution {
public:
    bool possible(vector<int>&bloomDay,int m,int k,int cap)
    {
        int i=0,c=0;
        while(i<bloomDay.size())
        {
            int n=i+k,j=i,f=0;
            if(n>bloomDay.size())break;
            while(n<=bloomDay.size() and j<n)
            {
                if(bloomDay[j]>cap)
                {
                    f=1;
                    i=j+1;
                    break;
                }
                j++;
            }
            if(f==0)
            {
                i=j;
                c++;
            }
        }
        // cout<<c<<" "<<cap<<" "<<m<<endl;
        return c>=m;
    }
    int minDays(vector<int>& bloomDay, int cap, int k) {
        if(1L*cap*k>bloomDay.size())return -1;
        unordered_map<int,int>mp;
        vector<int>temp;
        for(auto i:bloomDay)
        {
            mp[i]++;
            if(mp[i]==1)temp.push_back(i);
        }
        sort(temp.begin(),temp.end());
        //for(auto i:temp)cout<<i<<" ";
        // cout<<temp.size();
        int i=0,j=temp.size()-1,res=-1;
        while(i<=j)
        {
            int m=(i+j)/2;
            if(possible(bloomDay,cap,k,temp[m]))
            {
                // cout<<temp[m]<<" ";
                res=temp[m];
                j=m-1;
            }
            else i=m+1;
        }
        return res;
    }
};
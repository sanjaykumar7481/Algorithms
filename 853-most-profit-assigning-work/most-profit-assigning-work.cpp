class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res=0;
        vector<pair<int,int>>temp;
        for(int i=0;i<profit.size();i++)
        {
            temp.push_back({difficulty[i],profit[i]});
        }
        sort(temp.begin(),temp.end());
        vector<int>maxi(temp.size());
        maxi[0]=temp[0].second;
        for(int i=1;i<maxi.size();i++)maxi[i]=max(temp[i].second,maxi[i-1]);
        for(auto i:worker)
        {
            int a=0,b=profit.size()-1,p=0;
            while(a<=b)
            {
                int m=(a+b)/2;
                if(temp[m].first>i)
                {
                    b=m-1;
                }
                else
                {
                    p=max(p,maxi[m]);
                    a=m+1;
                }
            }
            res+=p;
        }
        return res;
        
    }
};
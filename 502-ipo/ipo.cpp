class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>temp(profits.size());
        for(int i=0;i<profits.size();i++)
        {
            temp[i]={capital[i],profits[i]};
        }
        sort(temp.begin(),temp.end());
        int start=0,res=w;
        priority_queue<pair<int,int>>pq;
        while(k--)
        {
            while(start<temp.size() and temp[start].first<=w)
            {
                pq.push({temp[start].second,temp[start].first});
                start++;
            }
            if(pq.empty())return res;
            res+=pq.top().first;
            // cout<<pq.top().first<<" ";
            // w-=pq.top().second;
            w+=pq.top().first;
            pq.pop();
        }
        // cout<<k<<" ";
        // cout<<pq.size();
        return res;
    }
};
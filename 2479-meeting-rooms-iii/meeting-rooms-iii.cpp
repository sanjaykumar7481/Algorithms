class Solution {
public:
    int mostBooked(int n, vector<vector<int>>&v) {
        map<long long,vector<pair<long long,long long>>>mp;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>> >pq;
        for(int i=0;i<n;i++)
        {
            pq.push({i,0});
        }
        sort(v.begin(),v.end());
        long long ans=0,res=n;
        long long timer=0,start=0,i=0;
        int next_timer=INT_MAX;
        mp[v[i][1]]={};
        while(i<v.size() or mp.size()!=0)
        {
            if(mp.find(timer)!=mp.end())
            {
                // cout<<timer<<endl;
                for(auto k:mp[timer])pq.push(k);
                mp.erase(timer);
            }
            while(i<v.size() and timer>=v[i][0] and !pq.empty())
            {
                long long delay=timer-v[i][0];
                auto a=pq.top();
                pq.pop();
                a.second++;
                if(a.second>=ans)
                {
                    if(a.second==ans)res=min(res,a.first);
                    else res=a.first;
                    ans=a.second;
                    // cout<<timer<<"t-"<<a.first<<" "<<a.second<<"->"<<v[i][1]+delay<<endl;
                }
                mp[v[i][1]+delay].push_back(a);
                i++;
            }
            if(pq.empty() and !mp.empty())
            {
                auto t=mp.begin();
                timer=t->first;
            }
            else timer++;
        }
        // cout<<mp.size()<<" size"<<endl;
        // cout<<endl;
        return res;
    }
};
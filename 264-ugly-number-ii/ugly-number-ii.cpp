class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>>pq;
        unordered_map<long,int>mp;
        pq.push(1);
        long ans;
        for(int i=0;i<n;i++)
        {
            ans=pq.top();
            pq.pop();
            mp[ans*2]++;
            if(mp[ans*2]==1)pq.push(ans*2);
            mp[ans*3]++;
            if(mp[ans*3]==1)pq.push(ans*3);
            mp[ans*5]++;
            if(mp[ans*5]==1)pq.push(ans*5);
        }
        return ans;
    }
};
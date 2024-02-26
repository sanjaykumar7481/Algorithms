class Solution {
public:
    void Union(int x,int y,vector<int>&parent,vector<int>&vis)
    {
        int a=get(x,parent);
        int b=get(y,parent);
        if(!vis[parent[a]] and !vis[parent[b]]){
            parent[a]=parent[b];
            return;
        }
        if(vis[parent[a]])
        {
            if(!vis[parent[b]])
            {
                parent[b]=parent[a];
            }
        }
        if(vis[parent[b]])
        {
            if(!vis[parent[a]])parent[a]=parent[b];
        }
    }
    int get(int a,vector<int>&parent)
    {
        return a==parent[a]?a:get(parent[a],parent);
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int>vis(n,0),res;
        vector<vector<int>>pq;
        vector<int>parent(n);
        for(int i=0;i<n;i++)parent[i]=i;
        vis[0]=1;
        vis[firstPerson]=1;
        res.push_back(0);
        res.push_back(firstPerson);
        for(auto i:meetings)
        {
            pq.push_back({i[2],i[0],i[1]});
        }
        sort(pq.begin(),pq.end());
        int i=0;
        vector<int>temp;
        while(i<pq.size())
        {
            int a=pq[i][0];
            int j=i;
            temp=parent;
            while(j<pq.size() and pq[j][0]==a)
            {
                auto k=pq[j];
                Union(k[1],k[2],temp,vis);
                j++;
            }
            j=i;
            while(j<pq.size() and pq[j][0]==a)
            {
                
                auto k=pq[j];
                int x=get(k[1],temp);
                int y=get(k[2],temp);
                if(vis[x])
                {
                    if(!vis[k[1]]){
                        vis[k[1]]=1;
                        res.push_back(k[1]);
                    }
                }
                if(vis[y])
                {
                    if(!vis[k[2]]){
                        vis[k[2]]=1;
                        res.push_back(k[2]);
                    }
                }
                j++;
            }
            temp.clear();
            i=j;
        }
        return res;
        
    }
};
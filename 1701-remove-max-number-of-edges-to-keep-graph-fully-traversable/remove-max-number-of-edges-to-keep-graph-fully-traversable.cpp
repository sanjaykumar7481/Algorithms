class Solution {
public:
    int find(int a,vector<int>&parent){
        if(a==parent[a])return a;
        return find(parent[a],parent);
    }
    void union_edge(int a,int b,vector<int>&parent,vector<int>&rank)
    {
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
    }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>parent(n+1),temp,rank(n+1,0),temp_rank;
        for(int i=1;i<=n;i++)parent[i]=i;
        vector<vector<int>>type1,type2;
        int present=0;
        for(auto i:edges)
        {
            if(i[0]==1)type1.push_back(i);
            else if(i[0]==2)type2.push_back(i);
            else
            {
                if(find(parent[i[1]],parent)!=find(parent[i[2]],parent))
                {
                    union_edge(i[1],i[2],parent,rank);
                    present++;
                }
            }
        }
        temp=parent;
        temp_rank=rank;
        for(auto i:type1)
        {
             if(find(parent[i[1]],parent)!=find(parent[i[2]],parent))
                {
                    union_edge(i[1],i[2],parent,rank);
                    present++;
                }
        }
        int ran=find(1,parent);
        for(int i=2;i<=n;i++)if(find(i,parent)!=ran)return -1;
        parent=temp;
        rank=temp_rank;
        for(auto i:type2)
        {
            if(find(parent[i[1]],parent)!=find(parent[i[2]],parent))
                {
                    union_edge(i[1],i[2],parent,rank);
                    present++;
                }
        }
        ran=find(1,parent);
        for(int i=2;i<=n;i++)if(find(i,parent)!=ran)return -1;
        return edges.size()-present;
        
    }
};
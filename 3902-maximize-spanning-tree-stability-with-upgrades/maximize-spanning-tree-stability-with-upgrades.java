class Solution {
    class UnionFind {

        int[] parent;
        int[] rank;

        public UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++) {
                parent[i] = i;   // each node is its own parent initially
                rank[i] = 0;
            }
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // path compression
            }
            return parent[x];
        }

        public void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) return;

            // union by rank
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } 
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } 
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    class edge implements Comparable<edge>{
        int u,v,s,must;
        edge(int u,int v,int s,int must){
            this.u=u;
            this.v=v;
            this.s=s;
            this.must=must;
        }

        public int compareTo(edge e){
            return e.s-this.s;
        }

    }
    public int maxStability(int n, int[][] edges, int k) {
        UnionFind uf=new UnionFind(n);
        PriorityQueue<edge>pq=new PriorityQueue<>();
        int stability=Integer.MAX_VALUE;

        for(int i=0;i<edges.length;i++){
            if(edges[i][3]==1){
                if(uf.find(edges[i][0])==uf.find(edges[i][1]))return -1;
                uf.union(edges[i][0],edges[i][1]);
                stability=Math.min(edges[i][2],stability);
                
            }
            else{
                pq.add(new edge(edges[i][0],edges[i][1],edges[i][2],edges[i][3]));
            }
        }
        Stack<Integer>st=new Stack<>();
        while(!pq.isEmpty()){
            edge e=pq.poll();
            if(uf.find(e.u)!=uf.find(e.v)){
                uf.union(e.u,e.v);
                st.add(e.s);
            }
        }
        while(!st.isEmpty()){
            int top=st.pop();
            if(k>0){
                top*=2;
                k--;
            }
            stability=Math.min(stability,top);
            
        }
        int par=uf.find(0);
        for(int i=1;i<n;i++)if(uf.find(i)!=par)return -1;
        
        return stability==Integer.MAX_VALUE?-1:stability;
    }
}
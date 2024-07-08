class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++)q.push(i);
        while(q.size()>1)
        {
            for(int i=0;i<k;i++)
            {
                int t=q.front();
                q.pop();
                if(i!=k-1)q.push(t);
            }
        }
        return q.front();
    }
};
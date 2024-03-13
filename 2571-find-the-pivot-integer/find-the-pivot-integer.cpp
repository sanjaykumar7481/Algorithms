class Solution {
public:
    int pivotInteger(int n) {
        int s=(n*(n+1))/2;
        int k=0;
        for(int i=1;i<=n;i++)
        {
            k+=i;
            if(k==s-k+i)return i;
        }
        return -1;
    }
};
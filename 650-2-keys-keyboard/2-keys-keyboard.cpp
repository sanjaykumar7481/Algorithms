class Solution {
public:
    int fun(int i,int size,int n){
        if(i==n)return 0;
        int ans=1e9;
        if(i+i<=n)ans=min(ans,2+fun(i+i,i,n));
        if(size!=0 and i+size<=n)ans=min(ans,1+fun(i+size,size,n));
        if(ans>1e9)ans=1e9;
        return ans;
    }
    int minSteps(int n) {
        return fun(1,0,n);
    }
};
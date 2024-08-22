class Solution {
public:
    int findComplement(int num) {
        int t=num<<1;
        if(t<0)return INT_MAX-num;
        long long p=1;
        while(t){
            p*=2;
            t>>=1;
        }
        p=p/2;
        num=~num;
        // num=num
        return p+num;
    }
};
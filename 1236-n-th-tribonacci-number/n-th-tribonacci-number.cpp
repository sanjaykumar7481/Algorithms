class Solution {
public:
    int tribonacci(int n) {
        long long a=0,b=1,c=1;
        long long res=0;
        while(n--){
            res=a+b+c;
            a=b;
            b=c;
            c=res;
        }
        return a;
    }
};
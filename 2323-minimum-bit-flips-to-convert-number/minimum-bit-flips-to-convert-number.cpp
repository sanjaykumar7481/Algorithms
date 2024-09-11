class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int min_flips=0;
        while(ans)
        {
            if(ans&1)min_flips++;
            ans>>=1;
        }
        return min_flips;
    }
};
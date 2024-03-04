class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int s=0;
        int a=0,b=tokens.size()-1;
        int ans=0,score=0;
        while(a<=b)
        {
            s+=tokens[a];
            ans=max(ans,score);
            while(a<=b and s>power and score--)
            {
                power+=tokens[b];
                b--;
            }
            if(power>=s){
                power-=s;
                s=0;
                score++;
            }
            else return max(ans,score);
            a++;
        }
        ans=max(ans,score);
        return ans;
    }
};
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c=0;
        for(auto i:logs)
        {
            if(i=="../")c=max(0,c-1);
            else if(i=="./")continue;
            else c++;
        }
        return c;
    }
};